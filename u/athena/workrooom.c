// ����ܰ(Athena)
// Room��/u/athena/workroom.c

#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
       set("short",MAG"��ܰС��" NOR); 
       set("long", 
"����һ�������ûʵĴ�լԺ����ͷ�ߴ��ʯʨ����ס�˴���
���࣬�����ϵ��������������������һ���ң�����"CYN"��"NOR""NOR+BLINK+HIG"�ո�"NOR""CYN"��"NOR" 
�������֡�
"HIY"-------------------------------------------------------"NOR"
��ɽ"HIG":"NOR""HIC"hs"NOR" ȫ��"HIG":"NOR""HIC"qz"NOR" ����"HIG":"NOR""HIC"yz"NOR" ̩ɽ"HIG":"NOR""HIC"ts"NOR" ����"HIG":"NOR""HIC"sl"NOR" �䵱"HIG":"NOR""HIC"wn"NOR" ����"HIG":"NOR""HIC"sn"NOR" 
ؤ��"HIG":"NOR""HIC"gb"NOR" ����"HIG":"NOR""HIC"xx"NOR" ����"HIG":"NOR""HIC"em"NOR" ����"HIG":"NOR""HIC"bt"NOR" ѩɽ"HIG":"NOR""HIC"xs"NOR" ����"HIG":"NOR""HIC"kl"NOR" ����"HIG":"NOR""HIC"bj"NOR"  
����"HIG":"NOR""HIC"xi"NOR" ����"HIG":"NOR""HIC"gy"NOR" ����"HIG":"NOR""HIC"dl"NOR" ����"HIG":"NOR""HIC"hz"NOR" ��Ĺ"HIG":"NOR""HIC"gm"NOR" ��ʦ"HIG":"NOR""HIC"wr"NOR" �һ�"HIG":"NOR""HIC"th"NOR":
"HIY"-------------------------------------------------------"NOR"\n");

        set("no_fight", 1);
        set("valid_startroom",1);
        set("exits", ([ /* sizeof() == 3 */
                  "hs"  : "/d/huashan/buwei1",
                  "qz"  : "/d/zhongnan/taijie2",
                  "yz"  : "d/city/kedian",
                  "ts"  : "/d/taishan/fengchan",
                  "north"  : "/u/athena/liuyuan",
                 "bt"  : "/d/baituo/btyard",
                  "sl"  : "/d/shaolin/guangchang1",
                  "wn"  : "/d/wudang/sanqingdian",
                  "sn"  : "/d/shenlong/tingkou",
                  "gb"  : "/d/gaibang/undertre",
                  "xx"  : "/d/xingxiu/xxh2",
                  "em"  : "/d/emei/hz_guangchang",
                  "xs"  : "/d/xueshan/guangchang",
                  "kl"  : "/d/kunlun/sanshengtang",                      
                  "bj"  : "/d/beijing/changanjie",
                  "xi"  : "/d/xixia/dawu",
                  "gy"  : "/d/taihu/qianyuan",
                  "dl"  : "/d/dali/wangfu1",
                  "hz"  : "/d/hangzhou/kedian",
                  "gm"  : "/d/gumu/dating",
                 "wr"  : "/d/wizard/wizard_room",
                  "th"  : "/d/taohua/jingshe",
]));
        set("objects", ([
                __DIR__"npc/meir" : 1,
                __DIR__"obj/bamboo" : 1,
]));
     call_other("/clone/board/athena_b", "???");


         setup();
        //replace_program(ROOM);
}

void init()
{
        object me = this_player();

        if( wizardp(me) && getuid(me)!="athena ")
                message("vision", me->name()+"���˹�����\n", environment(me), ({me}));

        add_action("do_leave", "leave");
        add_action("do_qu", "qu");
}

int valid_leave(object me, string dir)

{
        if (!wizardp(me))
                return notify_fail("ö����ס�������˵���������ţ�����û��ô���ף���\n");

        return ::valid_leave(me, dir);
}

int do_leave()
{
        object me = this_player();
        if(me)
                me->move("/d/city/wumiao");
        return 1;
}

int do_qu(string arg) {
        object me;

        me=this_player();
        if( !arg )
                return notify_fail("ȥ���\n");
        
        if( file_size("/u/"+arg + "/workroom.c") <= 0 )
                return notify_fail("���ڻ�û���Ǹ��ط���\n");
        message_vision(HIW"$N��һ�����䣬������һƬ������\n"NOR,
                this_player());
        this_player()->move("/u/"+arg+"/workroom");             
        message_vision(HIC"$NͻȻ������һ�������С�\n"NOR,me);
        return 1;
}
