// Code of ShenZhou
// baza ����
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��ά������У����۴�С�м�����֮Ϊ����������ÿ�������
����Ů���٣��޲��������룬���������¿�����Ǽݳ�ǣ�棬�ֻ�
ͽ�ֲ��У��Ӹ�����ʮ��ĵط����ϰ�������������������Ʒ����
���ϳ�ˮ����������������춶���
LONG
	);
	set("exits", ([ 
	    "southwest" : __DIR__"shule",
            "east" : __DIR__"baza2",
            "west" : __DIR__"baza3",
	]));
	set("objects", ([ 
	    "/d/xingxiu/npc/amite" : 1,
	    "/d/xingxiu/npc/w-girl" : 1,
	]) );
	set("outdoors","xingxiuhai");

	set("cost", 1);
	setup();
}
