//Modified by Zyu on k1-08-13
// qianting.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "ǰ��");
        set("long", @LONG
�����ǹ�������ǰ��Ͷʦ�ӵܵĵط����������ǲ��ס��������Ÿ���
������̴ľ���κͲ輸�����й�����λ֮��ڷ�һ����ʯ��������磬��
����һ��һ��������֮����ǽ�ϼ�����ˮ��С׭��ע����ݵĵ�ͼ(map)��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "west" : __DIR__"zoulang1",
            "east" : __DIR__"gardeno",
            "south" : __DIR__"shufang",
        ]));

        set("no_clean_up", 0);
        set("no_steal", 1);
        set("sleep_room", 0);
        set("valid_startroom",1);

        set("cost", 1);
        setup();

//      "/clone/board/wuguan_b"->foo();
}

void init()
{
        object me = this_player();

        add_action("help_map", "help");
        add_action("look_map", "look");
}

int help_map(string arg)
{
        object me = this_player();

        if ( !arg || arg=="" ) return 0;

        if ( arg!="map" ) return 0;

        tell_object(me,"������� look map ָ���������ݵĵ�ͼ��\n");

        return 1;
}

int look_map(string arg)
{
        object me = this_player();

        if ( !arg || arg=="" ) return 0;

        if ( arg!="map" ) return 0;

        tell_object(me,
                 HIC"\t\t\t��ݵ�ͼ\n\n"NOR
                +"         ���� \n"   
                +"           %\n"
                +"       ������ ������        ��ݺ�ɽ\n"
                +"           | /              /\n"
                +"  ����---����  װ����  ��ɽС·  ��̼�\n"
                +"           |      |      |       /\n"
                +"��Ϣ��---����---����---����---����---ǰ��---��԰��---����\n"
                +"          |       |            /               |\n"
                +"  ����---����  ҽ����     �����             ��԰---��԰�\n"
                +"          ��                                           /\n"
                +"       �Թ���                                      ����\n\n"
        );

        return 1;
}
