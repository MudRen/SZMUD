//Cracked by Roath
// yezi.c Ҭ��
// ssy
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("Ҭ��", ({ "yezi", "ye" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
		set("long", "һֻ��Ҭ�ӣ��������ˡ�\n");
                set("value", 70);
        }
        setup();
}
void init()
{
     add_action("do_eat", "eat");
     add_action("do_za", "za");
}

int do_za(string arg)
{
        object me = this_player();
        object stone,ke;
        int check;
	int level;

        if ( !arg )
                return notify_fail( "������ʲô��\n");
        if (( arg == "yezi" )||(arg == "ye"))
          {
	    if (!stone=present("shikuai",me))
	      return notify_fail( "��û�й��ߣ���ô�ң�\n");
	    else
	      {
		message_vision("$n��$N�߸߾��𣬺ݺݵ�����Ҭ���ϣ�", stone,me);
		level=(int)me->query_skill("hammer",1);
		check = level*level*level;
		if (level > 20)
		  {
		    write ("ֻһ�±��ҿ��ˣ�\n");
		  }
		else if (check > (int)me->query("combat_exp") * 10)
		  {       
		    write ("���˰��������ҿ��ˣ�\n");
		  }
		else
		  {
		    write ("���˰��������ҿ��ˣ������ѧ���˻��������ĳ���֪ʶ��\n");
		    me->improve_skill("hammer", me->query("int"));
		  }
		ke = new("/d/xiakedao/obj/yezike");
		ke->move(me);
		destruct(this_object());
		return 1;
	      }
          }
        else return 0;
}

int do_eat(string arg)
{ 
        object me = this_player();
        if ( !arg )
                return notify_fail( "�����ʲô��\n");
        if (( arg == "yezi" )||(arg == "ye"))
	  {
	    message_vision("$Nһ��ҧ��Ҭ�ӿ��ϣ������������ˣ��۵ý���һ����\n", me);
	    return 1;
	  }
	else return 0;
}



