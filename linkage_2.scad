scale(10) {
union() {
	difference() {
		cube([2,9,1]);
		translate([1,8,0])
			cylinder(r=.25,$fn=8);
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
	translate([1,0,0])
		cylinder(r=1,h=2,$fn=8);
	}
}