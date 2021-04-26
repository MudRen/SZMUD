// Code of ShenZhou
// Room: /d/mingjiao/szchang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "���쳡");
	set("long", @LONG
�ڳ����ϲ���һ����¯��¯�ڻ�׾�����һ�ߡ�һ����������µ��ӣ�
���Է���ʮ���������Ŀ��ת��������¯��ÿ��¯���ɫ���㽫����Щ
���͵ı�������¯����̽���������������һ����µ������������������䣬
����¯��ֱ������������ߴ�����εΪ��ۡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shanlu33",
  "north" : __DIR__"hqku",
]));
	set("objects", ([
		__DIR__"obj/ronglu": 1,
		__DIR__"obj/muzi": 1,
	]));

	set("cost", 1);

	setup();

}

int valid_leave(object me, string dir)
{
        if ((dir == "north" || dir == "west") && this_player()->query_temp("gun_making") )
               return notify_fail("�����ڴ����ǹ�������뿪���\n");
        return ::valid_leave(this_player(), dir);
}
