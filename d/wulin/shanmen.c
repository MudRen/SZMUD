// room /d/wulin/shanmen.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��ɽ��ˮ������·������������һ�塱��ͨ��ɽ������������һ����
�����۵�ɽ��ǰ��̧ͷ���������Կ���ɽ����д�š�����ͬ�ˡ���������
����Ĵ��֡�����������һС��·���ǻ�Хƺ�ˡ�

LONG
        );

        set("exits", ([
         "out" : "/d/taishan/fengchan",
         "northup" : __DIR__"huxiao",
        ]));

        set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/yishi" : 2,
        ]));
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}


