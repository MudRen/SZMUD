// room /d/wulin/longyin.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������ָ��ֶ���ʯ�ף����������������£����Ѿ�΢¶ƣ̬������
�����ϵ�ɽ·������ѣ��������ߣ���������һ�������̾���ϡ�ɽ�紵
�������������߿����ƣ����˺��������������¸ս�ˬ�ʵķ���뻢Хƺ
�������µ�������ӳ��Ȥ��һ�����־������ֵľ�����һ��ս����ǧ����
�����ɱ��
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"huxiao",
                "northup" : __DIR__"shanlu",
        ]));

        set("objects",([
                __DIR__"npc/yishi" : 1,
        ]));

        set("no_clean_up", 0);       
        set("cost", 1);
        setup();
}
