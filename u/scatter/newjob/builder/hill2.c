// newjob/builder/
//Jiuer  10/2001

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����һ�����ʯ����������ĸ�����׮��֧���ţ��ﶥ�ı��ü�Ƭ
��ϯΧ�ɵģ��ﶥ�����ż�Ƭ���ϯ������Сʯ��������ͷ��������������
��������Ļ�ƣ�һ���׺��������������Ų���ָ�������Ե����������
һ�����ʯ������������һ�����ӡ�
LONG);
	
	set("exits",([
		"east" : __DIR__"hill1",
		"west" : __DIR__"shop",
		]));
	
	set("objects", ([
		__DIR__"npc/shijiang" : 1,
		]));
	
	set("outdoors", "builder");
	set("cost", 0);
	setup();
	replace_program(ROOM);
}
