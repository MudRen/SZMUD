// �͸�spark�Ķ�ͯ��������  :)  presents.c
// by naihe  02-05-31  for spark.


#include <ansi.h>
inherit ITEM;

string now,now_muyang,now_where,
now="none",
now_where="ok";

void bian_gold();
void back();

void create()
{
	set_name(HIC"���ν��"NOR, ({"jingang", "kingkong","bianxing jingang"}));
	set("long","����һ�����ķ����Ķ�����ԭ���Ǹ����ν�ա�\n����԰����䣨bianxing���ɲ�ͬ�����ͣ��������棨play������\n");
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
	}
	setup();
}

void init()
{
	add_action("do_bianxing","bianxing");
	add_action("play_this","play");
}

int do_bianxing(string arg)
{
	object new_gold,me;
	me=this_player();
	new_gold=new("/clone/money/gold");
	new_gold->set_amount(1+random(5));

	if(!arg) return notify_fail("���Ա�ɣ�car gun plane �� gold .\n");

	if(arg!="car" && arg!="gun" && arg!="plane" && arg!="gold")
		return notify_fail("�ⶫ����Ū���������ֲ��ǰٱ��գ�\n");

	if(now_where!="ok") return notify_fail("��������û����Ү����ô����\n");

	now=arg;

	if(arg=="car")
	{
	    message_vision("$N����"HIC"���ν��"NOR"Ū��Ūȥ������Ū����һ��С����\n",me);
	    now_muyang="С��";
	}

	if(arg=="gun")
	{
	    message_vision("$N����"HIC"���ν��"NOR"Ū��Ūȥ������Ū����һ֧С��ǹ��\n",me);
	    now_muyang="С��ǹ";
	}

	if(arg=="plane")
	{
	    message_vision("$N����"HIC"���ν��"NOR"Ū��Ūȥ������Ū����һ��С�ɻ���\n",me);
	    now_muyang="С�ɻ�";
	}

	if(arg=="gold")
	{
	    message_vision("$N����"HIC"���ν��"NOR"Ū��Ūȥ������Ū������ˣ�ֻ�����������һЩ"HIY"�ƽ�"NOR"������\n",me);
	    new_gold->move(environment(me));
          bian_gold();
        return 1;
	}

	this_object()->set("long","����һ�����ν�գ����ڸ�Ū����"+now_muyang+"��ģ����\n����԰����䣨bianxing���ɲ�ͬ�����ͣ��������棨play������\n");
	return 1;
}

void bian_gold()
{
	destruct(this_object());
}

int play_this(string arg)
{
	object me,who,ob,yeah;
	me=this_player();
	yeah=new("/clone/money/silver");

	if(now=="none")
	{
		message_vision("$N�������ķ�����"HIC"���ν��"NOR"������ȥ�����ú�����Ŷ����\n",this_player());
		return 1;
	}

	if(now=="car")
	{
		if(now_where!="ok") return notify_fail("����"+now_muyang+"��û����Ү��\n");
		message_vision("$N����"+now_muyang+"����һ�ƣ�"+now_muyang+"�����ꤵع��˳�ȥ��\n",this_player());
		now_where="out";
		call_out("back",3+random(8));
		return 1;
	}

	if(now=="plane")
	{
		if(now_where!="ok") return notify_fail("����"+now_muyang+"��û����Ү��\n");
		message_vision("$N����"+now_muyang+"������һ�ţ�"+now_muyang+"���ݡ���һ�����˳�ȥ��\n",this_player());
		now_where="out";
		call_out("back",3+random(8));
		return 1;
	}

	if(now=="gun")
	{
		if(!arg)
		{
			message_vision("$N����"+now_muyang+"������ָ����������项�Ľ��ţ���ÿ��ļ��ˡ�\n",me);
			return 1;
		}

	        who=present(arg,environment(me));
      		if(!who) return notify_fail("����˭��\n");

		if(time()-query_temp("playtime")<3)
		{
		    message_vision("$N����"+now_muyang+"������ָ����������项�Ľ��ţ���ÿ��ļ��ˡ�\n",me);
		    return 1;
		}

                 tell_room(environment(me),me->query("name")+"����"+now_muyang+"ָ��"+who->query("name")+"����ؽе�����Ǯ����Ǯ������\n",({me,who}));
                  tell_object(who,me->query("name")+"����"+now_muyang+"ָ��������ؽе�����Ǯ����Ǯ������\n");
                  write("������"+now_muyang+"ָ��"+who->query("name")+"����ؽе�����Ǯ����Ǯ������\n");

		if(!present("silver_money",who) || random(2)==1)
		{
                        tell_room(environment(me),who->query("name")+"��Ц���ã�������"+me->query("name")+"��ͷ��˵������Сɵ�ϡ���\n",({me,who}));
			tell_object(who,"���Ц���ã�������"+me->query("name")+"��ͷ��˵������Сɵ�ϡ���\n");
			write(who->query("name")+"��Ц���ã����������ͷ��˵������Сɵ�ϡ���\n");
		}

		else
		{
                        tell_room(environment(me),who->query("name")+"��Ц���ã�ֻ���ͳ�һ�����ӵݸ�"+me->query("name")+"��˵�������ԣ����ǳ�Ŷ����\n",({me,who}));
			tell_object(who,"���Ц���ã�ֻ���ͳ�һ�����ӵݸ�"+me->query("name")+"��˵�������ԣ����ǳ�Ŷ����\n");
			write(who->query("name")+"��Ц���ã�ֻ���ͳ�һ�����ӵݸ��㣬˵�������ԣ����ǳ�Ŷ����\n");
			ob=(present("silver_money",who));
			ob->add_amount(-1);
			yeah->set_amount(1);
			yeah->move(me);
		}

		set_temp("playtime",time());
		return 1;
	}

	return 1;
}

void back()
{
	message_vision("ֻ��"HIC""+now_muyang+""NOR"ת�˸�Ȧ���ֶ��˻�����\n",this_player());
	now_where="ok";
}

