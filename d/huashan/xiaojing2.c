// Code of ShenZhou
// ��ɽС����
// qfy 25/7/1996

inherit ROOM;

void create()
{
	set("short", "Сľ��ǰ");
	set("long", @LONG
һ���ª��Сľ��ǰ����������һ��С����
LONG
	);

	set("outdoors", "huashan");

	set("exits", ([ /* sizeof() == 1 */
	"enter":__DIR__"xiaofang",
	"northwest":__DIR__"shaluo",
	"southwest":__DIR__"taogu",
]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
 
