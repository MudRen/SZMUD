// Code of ShenZhou
// /d/emei/qianfo1.c ǧ���ִ��
// Shan: 96/07/10

inherit ROOM;

void create()
{
        set("short", "ǧ���ִ��");
	set("long", @LONG
ǧ���ֵ���߹���������ׯ�ϡ�������һ������ǧ�����ƣ�����������
���ڵ��壬���з��������������У����ƾ����ޱȡ�
LONG
	);
	set("exits", ([
		"out" : __DIR__"qianfo",
		"east": __DIR__"chanfang_qf",
	]));

        set("objects",([
                __DIR__"npc/wenyin" : 1,
                CLASS_D("emei") + "/jinghui" : 1,
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

