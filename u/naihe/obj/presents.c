// Ϊspark��д��װ��Ʒ�ĺ��� :)  presents.c
// by naihe  02-05-31  for spark.

// ע�� ����ƷҪ�� babi-wawa.c �� bx-jingang.c ����ʹ�á�


#include <ansi.h>
inherit ITEM;

int now=10;
string color,color_name,obj;
void chai_obj();

void create()
{
	set_name(HIW"������Ʒ��"NOR, ({"box", "he","lipin he"}));
	set("long","����һ����Ư���İ�װֽ����������Ʒ�У�����Բ����chai����װֽ��������\n");
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
	add_action("do_chai","chai");
}

int do_chai(string arg)
{
	object new_ob,me;
	me=this_player();

	if(now==0)
	{
		message_vision("$N����պ��Ӳ𰡲�İ�����÷����ˡ�\n",me);
		call_out("chai_obj",0);
		return 1;
	}

	if(time()-query_temp("chaitime")<3) return notify_fail("���������Ʒ����ô�죬�������ڸ��ƻ�Ү����������ֱ�����������ˣ�\n");

	if(now!=10 && arg!=color_name) return notify_fail("������Ҫ��ɶ����\n");

	switch(random(5))
	{
		case 0:color_name="red";
		color=""HIR"��ɫ"NOR"��red��";
		break;
		case 1:color_name="green";
		color=""HIG"��ɫ"NOR"��green��";
		break;
		case 2:color_name="purple";
		color=""MAG"��ɫ"NOR"��purple��";
		break;
		case 3:color_name="blue";
		color=""HIC"��ɫ"NOR"��blue��";
		break;
		case 4:color_name="yellow";
		color=""HIY"��ɫ"NOR"��yellow��";
		break;
	}

	now--;
	if(now==0)
	{
		switch(random(2))
		{
		    case 0:new_ob=new(__DIR__"babi-wawa");
		    break;
		    case 1:new_ob=new(__DIR__"bx-jingang");
		    break;
		}

	message_vision("$N�������һ���װֽ���Ӻ������ó���һ"+new_ob->query("unit")+new_ob->query("name")+"��\n",me);
		new_ob->move(me);
		this_object()->set("long","����һ����Ʒ�У�����տյ�ʲô��û�С�\n");
		return 1;
	}

	else
	{
		this_object()->set("long","����һ����"+color+"��װֽ����������Ʒ�У�����Բ����chai����װֽ��������\n");
		message_vision("$NС������ز𿪰�װֽ���������滹��һ��"+color+"�İ�װֽ��\n",me);
	}

	set_temp("chaitime",time());
	return 1;
}

void chai_obj()
{
	destruct(this_object());
}

