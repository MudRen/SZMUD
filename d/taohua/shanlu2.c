// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
ɽ·�ߵ������ѷǳ����ͣ�ɽ·Ҳ���������������������ò����죬ÿ�߼�����
Ҫ�Ѳ���������̧ͷ��ȥ���������Ƿ嶥��
LONG
	);
	 set("exits", ([
                "southdown" : __DIR__"shanlu1",
                "northup" : __DIR__"tzfeng",
        ]));
	set("cost", 4);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
