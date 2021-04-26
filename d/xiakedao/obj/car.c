//Cracked by Roath
// Carriage: /clone/obj/car.c
// xbc: 04/15/1997

#include <ansi.h>
inherit ITEM;

void arrive(object, object, object, string, string, string);
int do_hire(string arg);

void create()
{
        set_name("��", ({ "da che", "che", "carriage"}) );
	set_weight(500000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("long", @LONG
����һ������ƥ�����ŵĴ󳵡���ǰ������һ���ϳ�����������
ֻ���ޡ������ﲻͣ�źߺ���ʲô���Ĳ����ɵ��������š�

����������������ӭ����˵�����⳵�����͵��������ġ�����ȥ
(qu)���Ҷ���������ȥ�����ݣ����ݣ�Ȫ�ݣ�̩ɽ�����֣�������
���ڣ��䵱�����ң��������ģ���ɽ�����ޣ�ѩɽ�����ݣ�����
�¿��ķ�ɽ��

LONG
	);
		set("value", 1000000);
		set("material", "steel");
		set("no_get",1);
	}
	setup();
}

void init()
{
	add_action("do_hire", "hire");
	add_action("do_hire", "gu");
	add_action("do_travel", "qu");
	add_action("do_travel", "goto");
}


int do_travel(string arg)
{
      object ob = this_object();
      object me = this_player();
	object ob2; 
	string destin, destch, destmg;

	if ( !arg ) 
		return notify_fail("�����ɻ���ʣ�ȥ���\n");
	
	if ( arg == "wudang" || arg == "�䵱" ) {
		destin = "/d/wudang/shanmen";
		destch = "�䵱";
		destmg = "��������������ɽ�������䵱���ӵ�Ҫȥ��������ϵ�����";
	}
	else if ( arg == "shaolin" || arg == "����" ) {
		destin = "/d/shaolin/shanmen";
		destch = "����";
		destmg = "��������ɽ�ţ�Ů�Ͳ��������ˣ�����Ϳ���ȥ�㳡����������ֻ�����ֵ��ӺͿ����ǲ��С�";
	}
	else if ( arg == "yangzhou" || arg == "����" ) {
		destin = "/d/city/kedian";
		destch = "����";
		destmg = "�������ݿ͵ꡣ�����˶��¶��࣬������ĵط�Ҳ�����š�";
	}
	else if ( arg == "xingxiu" || arg == "����" ) {
		destin = "/d/xingxiu/xxh2";
		destch = "���޺�";
		destmg = "�����޺�����ϡ�٣����������и�С�򡣿����������ߣ�С����������������޵��ӣ������ߵ�ɳĮ������·��";
	}
	else if ( arg == "shenlong" || arg == "����" ) {
		destin = "/d/shenlong/tanggu";
		destch = "������";
		destmg = "С��ֻ������������ˡ�Ҫȥ�������������Լ��д���������Ҫ��ȥ����ǧ��С�ģ�С�����������һ�����";
	}
	else if ( arg == "quanzhou" || arg == "Ȫ��" ) {
		destin = "/d/quanzhou/zhongxin";
		destch = "Ȫ��";
		destmg = "����Ȫ�����ģ������м������ۡ���������������߼���������Ȫ������ˡ�";
	}
	else if ( arg == "huashan" || arg == "��ɽ" ) {
		destin = "/d/huashan/yunu";
		destch = "��ɽ";
		destmg = "��ɽ�ɾ����ϱߡ�ɽ�Ϸ羰������ȥתת�������������һ�����";
	}
	else if ( arg == "taishan" || arg == "̩ɽ" ) {
		destin = "/d/taishan/wudafu";
		destch = "̩ɽ";
		destmg = "�����ҵ����ϲ�ȥ�������Լ�ȥ�ɡ���ɽС�ı�ˤ�š�ɽ���е����������������Ʒ���ʹ�ߡ�";
	}
	else if ( arg == "emei" || arg == "����" ) {
		destin = "/d/emei/baoguomen";
		destch = "����ɽ";
		destmg = "���Ƕ���ɽ������ɽ̫�������ϲ�ȥ���ſ��и�С������ͼ��������ɽ�������ˣ������ŵ����";
	}
	else if ( arg == "xueshan" || arg == "ѩɽ" ) {
		destin = "/d/xueshan/shanmen";
		destch = "��ѩɽ";
		destmg = "ѩɽ�ɾ����⸽�����������ߣ�С������ѩ����";
	}
	else if ( arg == "dali" || arg == "����" ) {
		destin = "/d/dali/wangfu1";
		destch = "�����"; 
		destmg = "����Ǵ���������������ˡ��������Ǹ�ԣ�ĺõط���ʲô�������С���������ɡ�";
	}
	else if ( arg == "xixia" || arg == "����" ) {
		destin = "/d/xixia/oldwall";
		destch = "���Ĺ�";
		destmg = "С�Ĳ������������ˣ�ȥ���Ĺ������Լ��д��ɡ�С�����������һ���ӡ�";
	}
	else if ( arg == "hangzhou" || arg == "����" ) {
		destin = "/d/hangzhou/kedian";
		destch = "����";
		destmg = "���ݵķ羰��������һ���ģ����Լ�����ת�ɡ�";
        }
	else if ( arg == "lanzhou" || arg == "����" ) {
		destin = "/d/qilian/lanzhou";
		destch = "����";
		destmg = "���ݿ��к�Щ�õط����ط���С����С�ı�ת���ˡ�";
	}
	else if ( arg == "foshan" || arg == "��ɽ" ) {
		destin = "/d/foshan/ngate";
		destch = "��ɽ";
		destmg = "��ɽ��·�����¿��ġ����ﱱ���䵱������Ȫ�ݣ���ͨ������ͨ��������������ɡ�";
	}
	else if ( arg == "xbc" ) {
		destin = "/u/xbc/workroom";
		destch = "�˽�";
		destmg = "С�ײ˵ļҡ�";
	}
	else return notify_fail("���򲻺���˼��˵������С�Ĳ���Ϥ�Ǳߵ�·����֪����ôȥ��\n");

	message_vision("$N�����󳵣��Գ���˵�˼��仰��\n�����������бޣ�ߺ���ţ�������������ȥ"+destch+"ඣ�\n\n", me);
  	tell_room(environment(me),"����������������Խ��ԽԶ������һ����Ͳ����ˡ�\n\n", me);
	
	ob2 = new(__DIR__"car2.c");

	me->move(ob2);
	ob->move(__DIR__"car3");
	tell_object(me, "�����������Ȼ��֪������龰�����λ����ƣ�ͣͣ���ߣ���֪���˶����졭��\n\n");

	me->start_busy(20);
	me->add_temp("paid", -1);

	remove_call_out("arrive");
	call_out("arrive", 40, me, ob2, ob, destin, destch, destmg);

	return 1;
}

void arrive(object me, object ob2, object ob, string destin, string destch, string destmg)
{

	ob->move(destin);
	me->move(destin);

        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob2);

	tell_room(environment(me),"��ƥ������һ�˴����˹���������һ��ߺ�ȣ���ͣ��������\n");

       message_vision("�������˵�����������������"+destch+"�����漴�ƿ����š�\n$N�ӳ�������������\n", me );
       message_vision(CYN "������˵����"+destmg+"��\n" NOR, me );
       message_vision("�������˵������" + RANK_D->query_respect(me) + "�����Ϊ֮�ɡ�������һ����ޣ��ݳ���ȥ��\n", me);
       call_out("destroy_it", 0, ob);	

}

void destroy_it(object obj)
{
        destruct(obj);
}

