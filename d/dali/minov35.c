// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "杆栏中层");
	set("long", @LONG
这里是杆栏的中层，从楼梯一上来就是祭所。南诏蛮夷大多信奉
自己部族特有的神明，家家户户都居中室设案供奉。中层的其余房间
则为寝所。此屋靠窗摆了一部纺纱机。
LONG
        );

	set("exits", ([
		"down" : __DIR__"minov34",
		]));

	set("objects", ([
		"/d/dali/npc/byfangsha.c" : 1,
		"/d/dali/obj/fangshaji.c" : 1,
		]));

	set("cost", 2);
	setup();
}
