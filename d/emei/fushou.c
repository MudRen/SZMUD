// Code of ShenZhou
// /d/emei/fushou.c ������
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
����������ˮ���ϣ���һ���������Ե�ɮ�˽���ġ���ǰ�о�����������
�أ����������ڴ������������۾���ʫ����ӽ��̾����֪Ϧ�ա����������
���������ٲ��䣬�ߴ�ʮ���ɡ�
LONG
	);
	set("exits", ([
		"north" : __DIR__"shenshui",
		"enter" : __DIR__"fushou1",
	]));

        set("objects", ([
		CLASS_D("emei") + "/jingzhen" :1,
		__DIR__"npc/f_dizi1" :1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 0);
	setup();
	replace_program(ROOM);

}
