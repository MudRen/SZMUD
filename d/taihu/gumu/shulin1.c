// Code of ShenZhou
//GU MU FROM SANTA
//SHULIN1.C

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������������ɽ��ɽ����Ƭ���֡������е������
�������ü����������������˱ǵĻ��㣬���㼸��
��Ϊ�ǵ����ɾ���ǰ�����˵Ĵ���һ���춯����֪
��ʲô������
LONG
	);

	set("exits", ([
		"south" : __DIR__"shulin2",
		"out"	  : __DIR__"houshan",	
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}



