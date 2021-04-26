inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "С��");
        set("long", @LONG
����һ���ɴ�����ʯ�̳ɵ�С·���䲻��˵��һ����Ⱦ����Ҳ������࣬
�����������˴�ɨ����������һ��С����������һ��ݵأ�������һ�����֡�
    ����ͣ����һ�԰׵�(diao)��
LONG
        );
         set("exits", ([
                "west" : __DIR__"caodi",
                "east" : __DIR__"shulin",
                "north" : __DIR__"tuqiu",
                "south" : __DIR__"haitan",
        ]));
        set("cost", 1);
        set("outdoors", "taohua");
		set("item_desc", ([
		"diao" : "����һ�԰�ɫ�Ĵ����չ�����ɡ�\n"
		"������һ����ĵ��ӣ�����(ride)�Ϳ��Էɵ�\n"
		"��ԭ������ȥ��ֻ���Եö�δ����ĺ��ӡ�\n",
				]));
        set("objects", ([
        ]));

        setup();
//      replace_program(ROOM);
}

void init()
{
    add_action("do_ride", "ride");
}

int do_ride ( )
{
    mapping myfam;
    object ob = this_player () ;
    myfam = (mapping)ob->query("family");
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
  tell_object(ob, "�����ڷɵ�����ԭ���׵�����������\n\n"  ) ;
  ob -> move ("/d/taihu/damen");
}
