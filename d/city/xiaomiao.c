// Code of ShenZhou
// Room: /city/minwu1.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
С���ﵽ��������֩��������̨������һ����Ļҳ���̨�Ϲ��Ĺ�������
����Ҳ�Ѿ���Ŀȫ���ˣ���������þ�û�����ˡ�ֻ�Ƕ����ſڵ�һ��С���Ե�
ʮ�ֵ��£��������滹��һ��û�г���ľƲˣ���֪��˭���µġ�������һ����
�˷������ţ����Ͽ���һ��С��(xiaozi)���������Ǹ��ܴ��Ժ�ӡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"dayuan",
		"north" : __DIR__"minwu2",
		"northwest" : __DIR__"xiaotulu",
		
	]));

	set("objects", ([
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

