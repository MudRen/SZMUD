// Code of ShenZhou
// jiuer 6/17/2002

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�������߸�����һ����Ժ�ӣ�����Զ������������ɳ�ѻ����ɵ�
����ɽ��ɽ��߸�¡���������յļ�����������Զ���������ն��ޱȵ���
��ɽ��ɽ����ϡ�ɼ����겻���İ�����ѩ��
LONG
	);
	set("exits", ([ 
	  //  "north" : __DIR__"btshan",
	    "east" : __DIR__"lingshege",
		"south" : __DIR__"kongdi2",
	  //  "southwest" : __DIR__"bedroom3",
	  //  "southeast" : __DIR__"kitchen",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
