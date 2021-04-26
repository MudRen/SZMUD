// Code by Felix
// Room: /u/smzz/workroom.c

inherit ROOM;
#include <ansi.h>
#include <room.h>
void reset();
int valid_leave();

void create()
{
set("short", HIC"ɳĮ֮�Ӱ칫��"NOR); 
set("long", 
""HIG"  ������ɳ���ﾺ����"NOR+HIM"  �������棬�������\n"NOR     
"               "HIY" ********************\n"NOR 
"                "HIY"*"NOR+BLINK+HIG" �������룬������� "NOR+HIY"*\n"NOR
"               "HIY" ********************\n"NOR 
""MAG"                      �� �� ��\n"NOR 
""MAG"             ������               ������\n" 
"             ������  ------------ ������\n" 
"             ���ҩ�  |          | ���㩦\n" 
"             ��һ��  |          | ��һ��\n" 
"             ������  |          | ��ǻ��\n" 
"             ���©� --------------��ȼ��\n" 
"             ���ᩦ_______________���թ�\n" 
"             ���ĩ�               ���ĩ�\n" 
"             ���ݩ�               ������\n" 
"             ���婦               ���驦\n" 
"             ������               ������\n"NOR
);
set("outdoors", "emei"); 





                  set("exits", ([
                "sl" : "/d/shaolin/guangchang1",
                "sn" : "/d/shenlong/tingkou",
                "xi" : "/d/xixia/dawu",
                "hz" : "/d/hangzhou/kedian",
                "wn" : "/d/wudang/sanqingdian",
                "xk" : "/d/xiakedao/dadong",
                "xx" : "/d/xingxiu/xxh2",
"athena":"u/athena/workroom",
"naihe":"u/naihe/workroom",
                "gy" : "/d/taihu/qianyuan",
                "kd" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",
"wm" : "d/city/wumiao",
                "hs" : "/d/huashan/pianting",
                "bt" : "/d/xingxiu/btyard",
"wz" : "/d/wizard/wizard_room",
"wr" : "/d/wizard/meeting_room",
                "wz" : "/d/wizard/wizard_room",
                "dl" : "/d/dali/wangfu1", 
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
"syj" : "/u/felix/syj",
  ])); 
set("item_desc", ([  
"diannao": HIW"��̨19�紿ƽ���Ժ�����������̧(tai)������\n"NOR,  
"bian": HIW"����ұ�����һ����ͨ���ң���ʵ�������ĳ�ʱ�մ����ǣ�
 ---------------------------------------------------- 
����: sl  �䵱: wn  ����: xx  ؤ��: gb  ����: bt
��ɽ: hs  ����: xk  �͵�: kd  ѩɽ: xs  ����: em
����: dl  ����: sn  ����: xi  �һ�: td  ����: gy
�ƽ���: wz ����wm
----------------------------------------------------
����Ը�������İ�ťȥ����ȥ�ĵط���\n"NOR,
"duilian": HIM"һ���ɽ�������д����������Ķ���\n"NOR
]));  
call_other("/clone/board/smzz_b", "???");

set("valid_startroom",1);

        setup();
}
void init()
{
    add_action( "tai", "tai" );
}

int tai( string arg )
{
if ( !arg || arg != "diannao" )
     return notify_fail( "��Ҫ̧ʲô��̧����������\n" );
   add( "exits/enter", __DIR__"room" );
tell_room( this_object(), HIW"һ���������������������©����һ���ڶ��������enter\n"NOR ); 
    return 1;
}

int valid_leave(object me, string dir)
{
object zhitiao;
                  if ( !wizardp(me) && dir!="up" ){
zhitiao=new("u/smzz/obj/zhitiao"); 
zhitiao->move(me); 
zhitiao->set("sign",me->query("id")); 
message_vision(HIW"��Ȼ"NOR+BLINK+YEL"��������"NOR+HIW"���˳�����������AK-47˵����#����%��������������#����\n"NOR+CYN"��һ���������ŵ����϶��ڵ�\n"NOR, me); 
command("say �࿴������İ��裬���磺�����ǡ�����ѽ��");
return notify_fail("�������Ǿ����㲻�ǻ��˵ݸ���һ�ź�С��ֽ����Ȼ��Ͳ����ˡ�\n"NOR);
        }
    else if ( dir == "enter" )
        call_out( "close_enter", 1 );
        return ::valid_leave(me, dir);
}

void close_enter()
{
    delete( "exits/enter" );
}
