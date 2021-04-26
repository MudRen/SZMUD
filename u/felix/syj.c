// Room: /u/felix/syj.c

inherit ROOM;
#include <ansi.h>


void init();
void close_dashi();
int do_push(string arg);
string look_dashi();

void create()
{
        set("short", HIW "ˮ�Ƽ�" NOR);
        set("long", @LONG
����������ɽ�����ȣ������������������ͱڡ��������£�������
�����ɽ����һ�����ٲ����������գ��������£�����һ���峺�쳣�Ĵ��
�С��ٲ�ע�봦��ˮ������������ٲ�ʮ���ɣ���ˮ��һƽ�羵����������
��������У�����Ҳ��һ�����Բ��(moon)��
LONG
        );
        set("valid_startroom", 1);
        set("outdoors", "wizard");
        set("exits", ([ /* sizeof() == 2 */
 // "enter" : __DIR__"direct.c",
 "out" : __DIR__"workroom.c",
    ]));

    set("item_desc",([
        "dashi"        :    (: look_dashi :),
        "moon" :       "��̧ͷ��������ȥ��ȴ�Ѽ�����������ԭ��������������䵽�������ͱ�֮�ᣬ
�ͱ�����һ���ף��¹��Զ��ױ˶��������������(hole)�������й��������\n",
        "hole" :       "����͸���ͱڶ��ף���һ�Ѳ�ɫ�ͷ׵Ľ�Ӱӳ��С��������ϡ��������Ͻ�
Ӱбָ�����������׼��һ�����ʯ(dashi)��\n",
    ]));

    setup();
}


void init()
{
    add_action("do_push", "push");
}

void close_dashi()
{
    object room;

    if(!( room = find_object(__DIR__"tomb")) )
        room = load_object(__DIR__"tomb");
    if(objectp(room))
    {
        delete("exits/down");
        message("vision", "����ʯ�����ֻص���ԭλ��\n", this_object());
        room->delete("exits/up");
        message("vision", "����ʯ�����ֻص���ԭλ��\n", room);
    }
    else message("vision", "ERROR: dashi not found(close).\n", room);
}


int do_push(string arg)
{
    object room;

    if (query("exits/down"))
        return notify_fail("����ʯ�Ѿ����ƿ��ˡ�\n");

    if (!arg || (arg != "rock" && arg != "dashi"))
        return notify_fail("��Ҫ��ʲ�᣿\n");

    if(!(room = find_object(__DIR__"tomb")))
        room = load_object(__DIR__"tomb");
        
    if(objectp(room))
    {
    if((int)room->query_temp("person_inside")<=0)
    {
                room->delete_temp("person_inside");
        set("exits/down", __DIR__"tomb");
        message_vision("$N˫�ֳ������ƣ��ǿ���ʯ��Ȼ΢΢ҡ�Σ�����ת����¶����һ���������ߵĶ�Ѩ��\n", this_player());
        room->set("exits/up", __FILE__);
//      message("vision", "���˴�����Ѵ���ʯ�ƿ��ˡ�\n", room);
        remove_call_out("close_dashi");
        call_out("close_dashi", 10);
    } else 
    {
        message_vision("$N��Ѵ���ʯ�ƿ���ȴ�������񱻿�ס�ˡ�\n",
                this_player());
    }
    }

    return 1;
}


string look_dashi()
{
    object room;

    if (query("exits/down"))
        return ("һ��޴����ʯ��������������ݸ��١�\n");

    if(!( room = find_object(__DIR__"tomb")) )
        room = load_object(__DIR__"tomb");

    if( objectp(room) )
    if( (int)room->query_temp("person_inside") > 0 )
    {
        return ("��С��ʯ֮���ٲݲ��ᡣ\n");
    } 
    
    return ("����һ��޴����ʯ���Ҹ����أ�û��ǧ��Ҳ��һǧ����������������(push)�ƿ���\n");
}


// End of file
