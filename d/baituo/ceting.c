// Code of ShenZhou
// jiuer 6/17/2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǰ���ɽׯ�Ĳ�������ׯ�����������ׯ���Ƿ���ׯ��ׯ����
СС�����ˡ�������ʩ�ȴ�����Щ�������������ڵ��������ر���
�������Ҵ���������������໥���Ƶľ��ߣ���Ŀ���࣬�����ޱȣ�����
ɱ����
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"changlang4",
		"north" : __DIR__"dating",
	]));

	//set("objects", ([ 
	//	CLASS_D("baituo")+"/ke" : 1,
	//	]) );
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
