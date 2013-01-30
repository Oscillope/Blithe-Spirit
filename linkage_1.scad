scale(10) {
union() {
	difference() {
		cube([2,11,1]);
		/*translate([0,2,0]) {
			translate([.75,0,0])
				cylinder(h=1, r=.5, $fn=3);
			translate([1.25,.75,0])
				rotate(a=180)
					cylinder(h=1, r=.5, $fn=3);
		}
		translate([0,3.5,0]) {
			translate([.75,0,0])
				cylinder(h=1, r=.5, $fn=3);
			translate([1.25,.75,0])
				rotate(a=180)
					cylinder(h=1, r=.5, $fn=3);
		}
		translate([0,5,0]) {
			translate([.75,0,0])
				cylinder(h=1, r=.5, $fn=3);
			translate([1.25,.75,0])
				rotate(a=180)
					cylinder(h=1, r=.5, $fn=3);
		}
		translate([.75,6.5,0])
			cylinder(h=1, r=.5, $fn=3);*/
	}
	hull() {
		translate([.5,.5,0])
			cylinder(r=1, $fn=100);
		translate([1.5,.5,0])
			cylinder(r=1, $fn=100);
	}
	difference() {
	translate([1,8,0])
		cylinder(h=2, r=.5, $fn=50);
	translate([1,8,0])
		cylinder(h=2, r=.15, $fn=50);
	}
}
translate([1,12,0]) {
	difference() {
		cylinder(r=2, $fn=100);
		cylinder(r=1, $fn=8);
	}
}
}