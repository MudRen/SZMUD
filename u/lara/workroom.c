// Room: /u/lara/workroom.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"��Ĺ��Ӱ������"+NOR);
        set("long", @LONG
���ǲ�����ʦ�����Ĺ����ң���������æ�ڲ��Թ��������ٻؼ�
��ɨ��������������˻ҳ���������֩������֩�������м�ֻ��ù��
С��(bug)����ס�ˡ�

LONG
        );
        set("exits", ([ 
                  "job" : "/d/wizard/job_room",
                  "huiyi"  : "/d/wizard/meeting_room",
                  "gumu"  : "/d/gumu/dating",
                  "mp"  : "/d/wizard/smiling_room",                  
                  "wg"  : "/d/wuguan/zhengting",                  
                  "clb"  : "/d/forest/clzoulang2",                  
                  "test"  : "/d/wizard/test_room",                  
                  "gold"  : "/d/wizard/wizard_room",                         
                  "bamboo" : "/d/wulin/xiaowu",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("item_desc", ([
              "bug" : "�ô��һֻ���棬�����ץ(catch)�����ｫ��������\n",
             
 ]));
        set("cost", 0);
        setup();
        call_other("/clone/board/lara_b", "???");
}
void init()
{   add_action("do_catch", "catch"); }

int do_catch (string arg)
{   object room;
    object me = this_player();
    if (!arg||arg!="bug") return notify_fail("��Ҫץʲô��\n");
    message_vision("$N��ݺݵ���ץס����棬����ȴץ�˸��ա�\n\n"
                   +HIB"ԭ����ֻ��һ����Ӱ......\n" 
                   +HIC"$N���в��죬��������һ�ᣬ�ѱ�ʱ��ת�Ƶ�������ͬ��ɽ�š�\n"NOR, me );
   
    me->move("/d/wulin/shanmen") ;

    return 1 ;
}

