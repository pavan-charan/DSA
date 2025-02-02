#include <stdio.h>
#include <stdlib.h>

// Structure representing a line segment
typedef struct {
    int start;
    int end;
} LineSegment;

// Structure representing an endpoint (either start or end of a segment)
typedef struct {
    int coordinate; // Position of the endpoint
    int type;       // Type: 0 = start, 1 = end
} Endpoint;

// Comparator for sorting endpoints
int compareEndpoints(const void *a, const void *b) {
    Endpoint *ep1 = (Endpoint *)a;
    Endpoint *ep2 = (Endpoint *)b;
    if (ep1->coordinate == ep2->coordinate) {
        return ep1->type - ep2->type;
    }
    return ep1->coordinate - ep2->coordinate;
}

// Create and sort endpoints from line segments
void createEndpoints(LineSegment *segments, int segmentCount, Endpoint **endpoints, int *endpointCount) {
    *endpointCount = segmentCount * 2;
    *endpoints = (Endpoint *)malloc(*endpointCount * sizeof(Endpoint));

    for (int i = 0; i < segmentCount; i++) {
        (*endpoints)[i * 2] = (Endpoint){segments[i].start, 0};
        (*endpoints)[i * 2 + 1] = (Endpoint){segments[i].end, 1};
    }

    qsort(*endpoints, *endpointCount, sizeof(Endpoint), compareEndpoints);
}

// Find the maximum length of overlapping segments
int maxSegmentLength(LineSegment *segments, int segmentCount) {
    Endpoint *endpoints;
    int endpointCount;
    createEndpoints(segments, segmentCount, &endpoints, &endpointCount);

    int maxLen = 0;
    int activeSegments = 0;
    int segmentStart = 0;

    for (int i = 0; i < endpointCount; i++) {
        if (endpoints[i].type == 0) { // Start of a segment
            activeSegments++;
            if (activeSegments == 1) {
                segmentStart = endpoints[i].coordinate;
            }
        } else { // End of a segment
            activeSegments--;
            if (activeSegments == 0) {
                int segmentEnd = endpoints[i].coordinate;
                maxLen = (segmentEnd - segmentStart > maxLen) ? segmentEnd - segmentStart : maxLen;
            }
        }
    }

    free(endpoints);
    return maxLen;
}

// Merge intervals from line segments
void mergeIntervals(LineSegment *segments, int segmentCount, int **mergedIntervals, int *intervalCount) {
    Endpoint *endpoints;
    int endpointCount;
    createEndpoints(segments, segmentCount, &endpoints, &endpointCount);

    *intervalCount = 0;
    *mergedIntervals = (int *)malloc(2 * segmentCount * sizeof(int));

    int activeCount = 0;
    int intervalStart = 0;

    for (int i = 0; i < endpointCount; i++) {
        if (endpoints[i].type == 0) { // Start of an interval
            activeCount++;
            if (activeCount == 1) {
                intervalStart = endpoints[i].coordinate;
            }
        } else { // End of an interval
            activeCount--;
            if (activeCount == 0) {
                (*mergedIntervals)[(*intervalCount) * 2] = intervalStart;
                (*mergedIntervals)[(*intervalCount) * 2 + 1] = endpoints[i].coordinate;
                (*intervalCount)++;
            }
        }
    }

    // Include original segments in the intervals
    for (int i = 0; i < segmentCount; i++) {
        (*mergedIntervals)[(*intervalCount) * 2] = segments[i].start;
        (*mergedIntervals)[(*intervalCount) * 2 + 1] = segments[i].end;
        (*intervalCount)++;
    }

    free(endpoints);
}

// Find the maximum length of transition from one color to another
int maxTransitionLength(LineSegment *color1, int count1, LineSegment *color2, int count2) {
    int *intervals1;
    int intervalCount1;
    mergeIntervals(color1, count1, &intervals1, &intervalCount1);

    int *intervals2;
    int intervalCount2;
    mergeIntervals(color2, count2, &intervals2, &intervalCount2);

    int maxLen = 0;
    int transitionFound = 0;

    for (int i = 0; i < intervalCount1; i++) {
        for (int j = 0; j < intervalCount2; j++) {
            if (intervals2[j * 2] < intervals1[i * 2 + 1] &&
                intervals2[j * 2] >= intervals1[i * 2] &&
                intervals2[j * 2 + 1] > intervals1[i * 2 + 1]) {
                int len = intervals2[j * 2 + 1] - intervals1[i * 2];
                if (len > maxLen) {
                    maxLen = len;
                }
                transitionFound = 1;
            }
        }
    }

    free(intervals1);
    free(intervals2);

    return transitionFound ? maxLen : -1;
}

int main() {
    int count;
    scanf("%d", &count);

    LineSegment *redSeg = (LineSegment *)malloc(count * sizeof(LineSegment));
    LineSegment *greenSeg = (LineSegment *)malloc(count * sizeof(LineSegment));
    LineSegment *blueSeg = (LineSegment *)malloc(count * sizeof(LineSegment));

    int redCount = 0, greenCount = 0, blueCount = 0;

    for (int i = 0; i < count; i++) {
        int start, end;
        char color[2];
        scanf("%d %d %1s", &start, &end, color);

        if (color[0] == 'r') {
            redSeg[redCount++] = (LineSegment){start, end};
        } else if (color[0] == 'g') {
            greenSeg[greenCount++] = (LineSegment){start, end};
        } else if (color[0] == 'b') {
            blueSeg[blueCount++] = (LineSegment){start, end};
        }
    }

    printf("%d\n", maxSegmentLength(redSeg, redCount));
    printf("%d\n", maxSegmentLength(greenSeg, greenCount));
    printf("%d\n", maxSegmentLength(blueSeg, blueCount));

    int transLen;

    transLen = maxTransitionLength(redSeg, redCount, greenSeg, greenCount);
    printf("%s\n", transLen != -1 ? (transLen > 0 ? "Transition found" : "nil") : "nil");

    transLen = maxTransitionLength(greenSeg, greenCount, blueSeg, blueCount);
    printf("%s\n", transLen != -1 ? (transLen > 0 ? "Transition found" : "nil") : "nil");

    transLen = maxTransitionLength(blueSeg, blueCount, redSeg, redCount);
    printf("%s\n", transLen != -1 ? (transLen > 0 ? "Transition found" : "nil") : "nil");

    free(redSeg);
    free(greenSeg);
    free(blueSeg);

    return 0;
}
