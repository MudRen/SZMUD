// Code of ShenZhou
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
���ǰ���ɽׯ��ǰԺ��Ժǽ��ש���ߣ�ǽ�Ͽ������಻��������
���ƣ�ټ���ɽׯ͸��һ�ɹ��ܵĸо��������ǰ���ɽׯ�Ĵ�������
�����߸���һ��С��������������֮�ᣬ������ɽȥ����ɽ�š�Ժ��
��һ�����ʯ��ɵĵ�ʯ����
LONG
	);
	set("exits", ([ 
		"eastdown" : __DIR__"btgate",
	    "west" : __DIR__"dating",
	    "north" : __DIR__"road1",
	    "south" : __DIR__"road1a",
	]));
	set("objects", ([
	    "/d/baituo/npc/binu" : 1,
	    "/d/baituo/npc/jiading" : 1,
	 ]) );
	set("outdoors","baituo");
      set("valid_startroom", 1);
	replace_program(ROOM);
	set("cost", 1);
	setup();
	"/clone/board/baituo_b"->foo();
}
