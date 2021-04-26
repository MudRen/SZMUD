//                ��׼��������ʾ��                                   |
// �����ҵıʼǱ������õģ��ٺ١���  ��/obj/note_naihe.c
// by naihe �κ�  2002-04-29  ����޸ģ�by naihe 02-06-28
// ������ı��ļ�Դ�룬лл��

#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
string user="spark";
string temp,dc_dirs,xianxing,
dc_dirs="/clone/misc/naihe/npc/obj/",
xianxing="no";

void create()
{
	set_name(YEL"��ʦ�ʼǱ�"NOR, ({"note", "note naihe"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ��С�ʼǱ���������д�������ʲݵ�С�֣�"HIC"�κ�"NOR"��\nС���Ա��ƺ����м��и�С���֣��㲻�����濴����looklook����\n");
		set("unit", "��");
		set("value", 1);
	}
	setup();
}

void init()
{
	add_action("do_bian",  "bian");
	if(this_player()->query("id")=="naihe")
		add_action("do_setuser", "setuser");
	add_action("do_xianxing","xianxing");
	add_action("do_cknow", "cknow");
	add_action("do_looklook","looklook");
	add_action("do_naihe","naihe");
	add_action("forme","forme");
	add_action("kissnaihe","kissnaihe");
}

int do_looklook()
{
	write("��������ű���������������䣬���䣨bian����һЩ������\n");
	write("����Բ鿴��cknow��һ�µ�ǰ����Ȩʹ���ߡ��ɱ����Ʒ��״̬��\n");
	write("����������naihe <��������>��Ťתʱ�գ�ʹ�Լ�˲�䵽��ĳ���ط���\n");
	write("����������forme��������Ȿ�ʼǱ���ʹ��Ȩ��\n");
	write("����������xianxing�����趨��Ҫ���ĵظɻ��Ҫ���˿�����\n");

	if(this_player()->query("id")==user) write("�������kissnaiheָ�����ָ�����hp��\n");

	if(this_player()->query("id")=="naihe")
	{
		write(HIY"���ڿ��Ա����Ʒ�У�(��ʽ��bian <obj_id> )\n jian/changjian/juice/cake/cloth/segar/gem/presents/huolu/caipu.\n�κΣ�naihe�������� setuser <id> ָ����Ȩ���ʹ�ã�\n�κ��˿����� cknow ָ����Բ�ѯ��ǰ��Ȩʹ���ߡ�\n"NOR);
		write(""HIR"����Ʒ����Ҳ���������С���趨��"NOR"\n");
		
	}
	return 1;
}

int do_xianxing(string arg)
{
	if(!arg || (arg!="yes" && arg!="no"))
		return notify_fail("��ʽΪ��xianxing <yes/no> .\n");

	if(this_player()->query("id")!="naihe" && this_player()->query("id")!=user)
		return notify_fail("��δ�����Ȩ��\n");

	xianxing=arg;
	if(xianxing=="yes") write("�Ѿ��趨Ϊ����ģʽ��\n");
	else write("�Ѿ��趨Ϊ���θɻ��ģʽ��������ʲô���˶������������� :)\n");
	return 1;
}

int kissnaihe()
{
	object me=this_player();

	if(me->query("id")!=user)
		return notify_fail("�������ҵ���\n");

	me->set("jingli",(int)me->query("max_jingli"));
	me->set("neili",(int)me->query("max_neili"));
	me->set("qi",(int)me->query("max_qi"));
	me->set("jing",(int)me->query("max_jing"));
	me->set("food",500);
	me->set("water",500);

	write("OK������hp�Ѿ����Ļָ���  : ) \n");
	return 1;
}

int do_naihe(string arg)
{
	object me=this_player();

	if(me->query("id")=="naihe" || me->query("id")=="spark" || me->query("id")==user)
	{
		if(xianxing=="yes") message_vision(""HIW"$N����С���ӵ������˾�ʲô����Ӱһ�Σ���Ȼ�ʹ���ʧ������"NOR"\n",me);
		else write(HIR"�����ĵ����·�����\n"NOR);
		if(arg=="naihe" || !arg) me->move("/u/naihe/naihe_room");
//		if(arg=="spark") me->move("/u/spark/spark_room");
		if(arg=="cs" || arg=="yangzhou") me->move("/d/city/guangchang");
		if(arg=="dc") me->move("/clone/misc/naihe/dc_dating");
		if(arg=="wiz") me->move("/d/wizard/wizard_room");
		if(arg=="shaolin") me->move("/d/shaolin/guangchang1");
		if(arg=="xixia") me->move("/d/xixia/center");
		if(arg=="hangzhou") me->move("/d/hangzhou/kedian");
		if(arg=="wudang") me->move("/d/wudang/sanqingdian");
		if(arg=="xingxiu") me->move("/d/xingxiu/xxh2");
		if(arg=="gaibang") me->move("/d/gaibang/undertre");
		if(arg=="gunyun") me->move("/d/taihu/qianyuan");
		if(arg=="huashan") me->move("/d/huashan/buwei1");
		if(arg=="baituo") me->move("/d/xingxiu/btyard");
		if(arg=="dali") me->move("/d/dali/wangfu1");
		if(arg=="emei") me->move("/d/emei/hz_guangchang");
		if(arg=="xueshan") me->move("/d/xueshan/guangchang");
		if(arg=="quanzhou") me->move("/d/quanzhou/zhongxin");
		if(arg=="quanzhen" || arg=="zhongnan") me->move("/d/zhongnan/gate1");
		if(arg=="lanzhou") me->move("/d/qilian/lanzhou");

		if(arg=="beijing") write("����ط��ĵ�ַ��û���ϡ�\n");
		if(arg=="changan") write("����ط��ĵ�ַ��û���ϡ�\n");
		if(arg=="gumu") write("����ط��ĵ�ַ��û���ϡ�\n");

		if(xianxing=="yes") message_vision(""HIW"$N����Ӱ��Ȼ����������ñ�������һ����"NOR"\n",me);
		else write(HIR"��һ�������������\n"NOR);
		return 1;
	}
	write("�㲢δ�����Ȩ��\n");
	return 1;
}

int do_bian(string arg)
{
	object me,bbb;
	int maxjing;

	me=this_player();
	maxjing=me->query("max_jing");

	if(!present("note naihe",me)) return notify_fail("�����������㿴�����������֡�\n");

/****************������idΪ"naihe",����Ϊ"�κ�"��ʱ��ִ�д˺����� **********************/

	if(me->query("id")=="naihe" && me->query("name")=="�κ�")
	{
		if(xianxing=="yes") message_vision(""HIY"$N����С�ʼǱ����૵��������ϡ������������������ߴ������������"NOR"\n",me);
		else write("�����ĵ���ű䶫���������\n");

/* ����������д��if(!arg && arg!="jian" && arg!="juice" && arg!="cake" 
&& arg!="cloth" && arg!="segar") return 1 �ģ����ǵ����ĵײ�Ҳ�������⣻����
���߾ȹ���ʹ����һ���жϷ�ʽ�� 

������һ�ַ�ʽҲ���д�ʲô�ײ���ٻ�һ�ַ�ʽ������(!bbb) */

		if(!arg)
		{
			if(xianxing=="yes") message_vision("���ʲôҲû������$N�����Լ����Ǹ���ľ�ϡ�\n",me);
			else write("���ʲôҲû������----���������ı����ǿ������� :) \n");
			return 1;
		}

		if(arg=="jian") bbb=new(__DIR__"anyue-jian");
		if(arg=="changjian") bbb=new(__DIR__"changjian");
		if(arg=="juice") bbb=new(dc_dirs+"ajuice");
		if(arg=="cake") bbb=new(dc_dirs+"cake");
		if(arg=="cloth") bbb=new("/clone/misc/cloth");
		if(arg=="segar") bbb=new(dc_dirs+"segar");
		if(arg=="gem") bbb=new(__DIR__"gem");
		if(arg=="presents") bbb=new(__DIR__"presents");
		if(arg=="huolu") bbb=new(__DIR__"huolu");
		if(arg=="caipu") bbb=new(__DIR__"caipu");

		if(!bbb)
		{
			if(xianxing=="yes") message_vision("$N�����е��������䣡��Ҫ��� "+arg+" ����������������ȴ�䲻������\n",me);
			else write("���ڵ��趨��û��"+arg+"�����������䲻������\n");
			return 1;
		}

		if(arg=="jian")
		{
			if(!present("anyue jian", me))
			{
				if(xianxing=="yes") message_vision("$N�����һ��"BLU"����֮��"NOR"��\n",me);
				else write("�ã�����˰���֮����\n");
				bbb->move(me);
				return 1;
			}
			write("------���ϲ�����һ���𣬱���ô����ʲô��\n");
			if(xianxing=="yes") message_vision("���ʲôҲû������$N�����Լ����Ǹ���ľ�ϡ�\n",me);
			else write("ʲôҲû�����Ŷ������\n");
			return 1;
		}

		switch(random(2))
		{
			case 0 :
			if(xianxing=="yes")
			{
				message_vision(""MAG"ֻ����һ�����ĵ�̾Ϣ����֪���Ĵ��˹�����$Nһ���Ӵ�ס�ˣ���������˸��"NOR"\n",me);
				message_vision("$Nһ���ò��ȣ�С���ӵ����˵��ϡ�\n",me);
				temp="yeah";
			}
			else write("������鲻�ԣ��䲻���������Ӳ���� :)\n");
			break;

			case 1 :
			if(xianxing=="yes") message_vision("$N�����һ"+bbb->query("unit") + bbb->query("name") + "��\n",me);
			else write("������һ"+bbb->query("unit") + bbb->query("name") + "��\n");
			bbb->move(me);
			temp="none";
			break;
		}			
		if(temp=="yeah") this_object()->move(environment(me));
		return 1;
	}

/***********������idΪnaihe�趨��id��ʱ��ִ�����º�����****************/

	if(me->query("id") == user && user!="naihe")
	{
		if(xianxing=="yes") message_vision(""HIY"$N����С�ʼǱ����૵��������ϡ������������������ߴ�����������ް�ѽ������"NOR"\n",me);
		else write("�����ĵ������˱䶫���������\n");
		temp="none";

		switch(random(8))
		{
			case 0 :
			bbb=new(__DIR__"anyue-jian");
			break;

			case 1 :
			bbb=new(__DIR__"changjian");
			break;

			case 2 :
			bbb=new(__DIR__"jiudai");
			break;

			case 3 :
			bbb=new("/clone/food/kaoya");
			break;

			case 4 :
			bbb=new("/clone/misc/cloth");
			break;

			case 5 :
			bbb=new(dc_dirs+"ojuice");
			break;

			case 6 :
			bbb=new(dc_dirs+"segar");
			break;

			case 7 :
			if(xianxing=="yes")
			{
				message_vision(""HIR"ֻ���κ�һ���Ӵ�$Nǰ��ð�˳��������������������ˣ�ľ�ϣ���ľ�ϣ���"NOR"\n",me);
				message_vision("$N�ŵ���һ���£�С���ӵ����˵��ϡ�\n",me);
				temp="yeah";
			}
			else write("����ʲô���䲻������������ĳɹ��ʻ��д���ǿѽ��\n");
			break;			
		}
		if(temp=="yeah")
		{
			this_object()->move(environment(me));
			return 1;
		}

		if(!bbb) return 1;
		bbb->move(me);
		if(xianxing=="yes") message_vision("$N�����һ"+bbb->query("unit") + bbb->query("name") + "��\n",me);
		else write("������һ"+bbb->query("unit") + bbb->query("name") + "��\n");
		me->add("jing",-(maxjing/10));
		if(xianxing=="yes") message_vision("$N����ʹ�÷����������е���ѣ�ˡ�\n",me);
		else write("��ʹ�÷�����������ղź��ˡ�\n��Щ���鶼�����ĸɵģ����˲�֪��������\n");
		return 1;
	}

/***********�����˲���naihe��Ҳ�����趨��user�����Ǹ���ʦ��ʱ��ִ�����º�����	************/

	if(me->query("id")!="naihe" && me->query("id")!=user && wizardp(me))
	{
		message_vision(""HIY"$N����С�ʼǱ����˰��죬��Ц���õ�˵�������κ���С�ӣ�д����Щ�ô��룡��"NOR"\n˵��$NҲ�����������������۹�Ӵ����զ������������\n����ȴʲôҲ�䲻�����������κ����ıʼǻ��湻�õġ�\n",me);
		return 1;
	}

/*********************��������ȫ�Ǹ������˵�ʱ��ִ�����º�����***********************/

	message_vision("$Nɵ�����ض���С����ߴߴ�����Ĳ�֪������Щʲô��\n",me);
	write("��֪��ô�ģ������ͷ��Щ�����ˡ�\n");
	me->add("jing",-(maxjing/10));
	return 1;
}

int do_setuser(string arg)
{
	if(!arg) return notify_fail("��ʽ��setuser <id>\n");
	user=arg;
	write("set user ok. the user is ��"+user+"��.\n");
	return 1;
}

int do_cknow()
{
	write("���ڵ���Ȩʹ�����ǣ�"+user+"���ɻ�ģʽ�趨Ϊ ");
	if(xianxing=="yes") write("���Ρ�\n");
	else write("���Ρ�\n");
	if(this_player()->query("id")=="naihe")
	{
write("�����ڿɱ����Ʒ�У�jian/changjian/juice/cake/cloth/segar/gem/presents/huolu/caipu.\n");
write("��Ȩʹ����");
	}
        else if(this_player()->query("id")==user) write("��");
		else write("��Ȩʹ����");
	write("���л����� ���½����������ƴ�����Ѽ�����¡�����֭��ѩ���̡�\n");
	return 1;
}

int forme()
{
	object me=this_player();

	if(me->query("id") =="naihe") return notify_fail("�����ջ����ˣ�����\n");
	if(me->query("id") == user) return notify_fail("�Ȿ�ӱ��������������\n");
	if(wizardp(me))
	{
	    user=me->query("id");
	    write("������ʦ�����Ի����Ȩ��\n");
	}
	if(this_player()->query("id")=="jionsion") user="jionsion";
	if(this_player()->query("id")=="yijiu") user="yijiu";
	if(this_player()->query("id")=="spark") user="spark";

	if(this_player()->query("id")!=user) write("�Բ����㲢û�л����Ȩ��\n");
	write("���ڵ���Ȩʹ�����ǣ� "+user+".\n");
	return 1;
}
