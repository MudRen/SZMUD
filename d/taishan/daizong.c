// Code of ShenZhou
// Room: /d/taishan/daizong.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "��ڷ�");
	set("long", @LONG
λ��̩���س��Ա�Լһ��˴��ǵ�̩ɽ����ڡ��ഫ�����ϼԪ��������
��ϷŪ������Ͷ���廨Ь�Զ�̩ɽ�ؽ磬�����ϼԪ��ֻ�ܰ��廨Ь��ɽ������
�˴����Ӵ�̩ɽ���Դ�Ϊ��㡣̩ɽ�������ǻƺӡ�
LONG
	);

	set("exits", ([
		"northup" : __DIR__"baihe",
		"south" : __DIR__"yidao3",
		"west" : "/d/huanghe/bank5",
	]));

        set("objects",([
                "/clone/npc/shan" : 1,
        ]));

	set("outdoors", "taishan");
	set("cost", 4);
	setup();
	replace_program(ROOM);
}

