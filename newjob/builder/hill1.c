//Created by Jiuer on Oct 26/2001

inherit ROOM;

void create()
{
	set("short","矿山");
	set("long",@LONG
这是一片荒山崖壁，山石陡峭，寸草不生，地上偶然爬过一
只壁虎，看来这里到是采石的好地方。
LONG
	);
	set("exits",([
		"west" : __DIR__"hill2",
	//  "east" : ,
		]));
	
	set("outdoors", "builder");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}
