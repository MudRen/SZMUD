// Code of ShenZhou
// baza ����
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����ǰ����Ķ�ͷ����ʽ�������������߹�������Ʒ��Ӧ�о�
�С���������ɽ�˺�����ͷ�ܶ��������ǽ��������ּ�������¿����
LONG
	);
	set("exits", ([ 
            "west" : __DIR__"baza1",
	]));
	set("objects", ([ 
	    "/d/xingxiu/npc/aixihan" : 1,
//	    "/d/xingxiu/npc/w-girl" : 1,
	]) );
	set("outdoors","xingxiuhai");

	set("cost", 1);
	setup();
}
