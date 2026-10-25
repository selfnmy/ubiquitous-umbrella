/*

// arithmetic prog
arith_nth = a1 + (n - 1) * d
arith_sum = n * (a1 + arith_nth) / 2

// geometric prog
if q != 1:
    geom_sum = a1 * (q^n - 1) / (q - 1)
else:
    geom_sum = n * a1

// triga
sin_sq_a = (1 - cos(2 * a)) / 2

sin_sum = 2 * sin((a + b) / 2) * cos((a - b) / 2)
sin_diff = 2 * sin((a - b) / 2) * cos((a + b) / 2)

cos_sum = 2 * cos((a + b) / 2) * cos((a - b) / 2)
cos_diff = -2 * sin((a + b) / 2) * sin((a - b) / 2)

cos_sum_angle = cos(a) * cos(b) - sin(a) * sin(b)
sin_sum_angle = sin(a) * cos(b) + cos(a) * sin(b)

// triangle area by coordinates
area_triangle_coords = 0.5 * abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1))

// triangle area by Heron's formula
p = (a + b + c) / 2
area_triangle_heron = sqrt(p * (p - a) * (p - b) * (p - c))

// sphere surface area
sphere_surface_area = 4 * pi * R^2

// sphere volume
sphere_volume = (4 / 3) * pi * r^3

// cone or pyramid volume
base_area = S_osn
cone_pyramid_volume = (1 / 3) * base_area * h

// law of cos
side_c_sq = side_a^2 + side_b^2 - 2 * side_a * side_b * cos(angle_C)

// law of cos (forms)
cos_angle_A = (side_b^2 + side_c^2 - side_a^2) / (2 * side_b * side_c)
cos_angle_B = (side_a^2 + side_c^2 - side_b^2) / (2 * side_a * side_c)
cos_angle_C = (side_a^2 + side_b^2 - side_c^2) / (2 * side_a * side_b)

// law of sin
side_a / sin(angle_A) = side_b / sin(angle_B) = side_c / sin(angle_C) = 2 * R_circum

// law of sin (inv form)
sin(angle_A) / side_a = sin(angle_B) / side_b = sin(angle_C) / side_c = 1 / (2 * R_circum)

// sector area (angle in radians!)
sector_area_rad = 0.5 * theta * r^2

// sector area (angle in degrees!)
sector_area_deg = (pi * r^2 * alpha) / 360

*/
