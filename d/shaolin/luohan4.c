// Code of ShenZhou
// Room: /d/shaolin/luohan4.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�޺�����");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬��
�ڿյ����ر��������������İڷ��ż��������ҷ��ڵĻƲ�
���ţ���λ�뷢���׵���ɮ�������������Ŀ�붨�������Ǳ���
ʮ���޺��������еĵط������پ����书�����ڴ������
LONG
	);

	set("exits", ([
		"south" : __DIR__"luohan3",
		"north" : __DIR__"luohan5",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/cheng-jing" : 1,
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}



