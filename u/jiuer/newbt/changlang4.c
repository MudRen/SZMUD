// Code of ShenZhou
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ����ש��ǽ�ĳ��ȣ����ߵĹ���ͨ������������С���ǰ���ɽׯ��
��ʦ��ס�ķ��䡣�ϱ���һ�����������ׯ�����������ׯ���ǽ������
���ļ��ɡ�
LONG
	);
	set("exits", ([ 
	    "north" : __DIR__"ceting",
	    "west" : __DIR__"bedroom2",
		"south" : __DIR__"liangongfang",
	  //  "southwest" : __DIR__"bedroom3",
	  //  "southeast" : __DIR__"kitchen",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
