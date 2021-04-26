inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "����");
        set("long", @LONG
��ǰ��һ��ׯԺ����¥�����ߴ���ש���ߣ���ɫ�׵�����д��
������ׯ����������֡����ҽ�Ϊ�¾ɣ��߽Ǵ�����Ƥ�Ѱ��䣬¶��
����ɫ��ľ�ʡ������������Ѳ��¶�ʮ�������ˡ�
    ��ǰͣ����һ�԰׵�(diao)��
LONG
        );
         set("exits", ([
                "enter" : __DIR__"qianyuan",
                "south" : __DIR__"matou",
        ]));
        set("cost", 1);
        set("outdoors", "taihu");
		set("item_desc", ([
		"diao" : "����һ�԰�ɫ�Ĵ����չ�����ɡ�\n"
		"������һ����ĵ��ӣ�����(ride)�Ϳ��Էɵ�\n"
                "�һ���������ȥ��ֻ���Եö�δ����ĺ��ӡ�\n",
				]));
        set("objects", ([
                "/d/taihu/npc/jiading" : 2,
        ]));

        setup();
//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    mapping myfam = (mapping)me->query("family");

    if ( (!myfam || myfam["family_name"] != "�һ���") && (dir == "enter") && (!me->query_temp("guiyun")) && present("jia ding", environment(me)))
        return notify_fail("�Ҷ����˸�Ҿ��˵����������ׯ����������ׯ��������ͣ�������ذ�\n");

    return ::valid_leave(me, dir);
}

void init()
{
    add_action("do_ride", "thd");
    add_action("do_ride", "ride");
}

int do_ride ()
{
    mapping myfam;
    object ob = this_player () ;
    myfam = (mapping)ob->query("family");
/*
        if ( !arg || arg == "")
 return notify_fail("��Ҫ��ʲô��\n"); 
if( arg != "diao") return 0;
*/
	if( (int)ob->query("str") > 26 ) 
         return notify_fail("�׵񷢳��˼��������ĲҽУ�ԭ��������ѹ���ˡ�\n");
    if(!myfam || myfam["family_name"] != "�һ���")
    {
      message_vision("$NһԾ������˰׵�ֻ���׵����쳤ণ�ͻȻ��Ȼһ��......\n"
                     HIR "���$Nˤ�˸��������ף�\n" NOR
                     "�����׵��$N��������Ȥ����ֻ��ʶ�һ����ĵ��ӡ�\n" , ob ) ;
      ob -> receive_damage ("qi",50) ;
      ob -> receive_wound  ("qi",50) ;
      return 1;
    }
	if( (int)ob->query("age") > 18 ) 
         return notify_fail("�׵��˴��˼��³�򣬵���û�з���������Ȼ������̫���ˡ�\n");
    if( (int)query("sb_ride") ) 
         return notify_fail("���ڰ׵���æ��,���һ���ٳ���!\n" ) ;
    add("sb_ride",1) ;
    message_vision(HIW"$NһԾ������˰׵�ֻ���׵����쳤ণ�ͻȻչ��߷ɡ�\n\n"NOR
                   HIW"����һ��һ�����ν�����С������������\n" NOR, ob );
    ob->move("/d/taohua/lantian") ;
    tell_object(ob, CYN  "\n�㲻�ϵط�ѽ�ɣ���ˮǧɽ����Ʈ�� ......\n\n" NOR ) ;
    call_out("taohua", 3 , ob );
    add("sb_ride",-1) ;
    return 1 ;
}
void taohua( object ob )
{
  tell_object(ob, "�����ڷɵ����һ������׵�����������\n\n"  ) ;
  ob -> move ("/d/taohua/haitan");
}
