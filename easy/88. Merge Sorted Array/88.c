void merge(int *nums1, int m, int *nums2, int n) {
    int im = m - 1, in = n - 1;
    for (int i = m + n - 1; i >= 0; i--) {
        if (nums1[im] > nums2[in]) {
            nums1[i] = nums1[im];
            im--;
        } else {
            nums1[i] = nums2[in];
            in--;
        }
        if (in < 0) {
            return;
        }
        if (im < 0) {
            for (int j = 0; j <= in; j++) {
                nums1[j] = nums2[j];
            }
            return;
        }
    }
}