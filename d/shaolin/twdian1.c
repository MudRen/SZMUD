// Code of ShenZhou
// Room: /d/shaolin/twdian1.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�����");
	set("long", @LONG
�����Ƕ����������������Ŵ�Ħ��ʦ��������ʿ�Ļ�
���Լ�һЩ����Ԫ�ϵ��ֻ�������ɢ�ҵط���������ţ�ľ
��ȡ������˴��Ǳ��ɵ��Ӵ�������֮������λ��������ֳ�
���飬���������
LONG
	);

	set("exits", ([
		"west" : __DIR__"twdian",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



