// Code of ShenZhou
// wannian1.c ������ש��
// Shan: 96/07/09

inherit ROOM;

void create()
{
        set("short", "������ש��");
	set("long", @LONG
�����������ֵĹ�������ש�ש���ı�Ϊ�����Σ���Ϊ���Բ���Σ���
�����������������������ͭ����һ�𡣹�������ש���ı��·�����С���ʮ
�ĸ����ڸ�����������һ���ı��Ϸ����к�������������ͭ��С����������
����
LONG
	);
	set("exits", ([
		"out" : __DIR__"wannian",
		"east": __DIR__"chanfang_wn",
	]));

        set("objects",([
		__DIR__"npc/wenfang" : 1,
                CLASS_D("emei") + "/jingkong" : 1,
        ]));

	set("cost", 0);
	setup();
	replace_program(ROOM);

}

