// Code of ShenZhou
// zhongfeng.c �з���
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "�з���");
	set("long", @LONG
�з����ڰ��Ʒ��£�ʼ���ڽ�����ԭΪ���ۡ���˵���ڵĵ���ÿ��������
���ն������ɽ��һ����������Ϊ�������ɡ������и�����������������ʦ��
ɱ��������������ʿ��ʼ֪�ϵ����м����ѣ���Ը���ŷ�̣��Ӵ˸Ĺ�Ϊ�¡�
���������ɵ������󣬶�������ˮ�֡�
LONG
	);
	set("exits", ([
		"northwest" : __DIR__"qingyin",
		"eastdown" : __DIR__"shenshui",
	]));

        set("objects", ([
		__DIR__"npc/xiang-ke" :1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 1);
	setup();
	replace_program(ROOM);

}
