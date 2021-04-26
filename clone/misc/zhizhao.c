// vendor_pass.c ��ҵִ��

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("��ҵִ��", ({ "shangye zhizhao", "zhizhao" }) );
	set_weight(1);
	if( clonep() )
	set("long", "һ�ź�׽�����ӣ�����д���ĸ���ӲӵĴ��֣���ҵִ�գ����½��ǻ�����ױ�ǩ����\n");
	set("unit", "��");
	set("value", 0);
	set("material", "paper");
	set("no_get",1);
	set("no_give",1);
	set("no_sell",1);
	set("no_steal",1);
	setup();
}

void init()
{
       add_action("do_bantan", "baitan");
       add_action("do_shoutan","shoutan");
       add_action("do_stock","stock");
       add_action("do_unstock","unstock");
	   add_action("do_checksellerrating", "checksellerrating");
}

int do_bantan()
{
        object obj,me;
        obj = this_object();
        me = this_player();

        if (!me->query("is_vendor")) return notify_fail("���ֲ������ˣ�Ϲ����ʲô����\n");
        if (!present("shangye zhizhao",me)) return notify_fail("�����ҵִ�ղ������ϣ��ѵ�����֤��̯��\n");
        if (me->query_temp("on_bantan")) return notify_fail("���Ѿ�ռ��һ��̯λ���������ģ�\n");

        message_vision(HIW "$N����һ��յأ�һƨ����������������ͳ�һ�鲼̯���ڵء�\n" +NOR,me);
        tell_object(me,HIW "��������԰���(stock)�����ˣ���Ҳ��������(unstock)ĳ�ֻ��\n");
        me->set_temp("on_bantan",1);
        me->delete("vendor_goods");
        return 1;
}

int do_shoutan()
{
        object obj,me;
        obj = this_object();
        me = this_player();

        if (!me->query("is_vendor")) return notify_fail("���ֲ������ˣ�Ϲ����ʲô����\n");
        if (!present("shangye zhizhao",me)) return notify_fail("�����ҵִ�ղ������ϣ������ߺ��������߲�����һ���µġ�\n");
        if (!me->query_temp("on_bantan")) return notify_fail("�㲢û�а�̯����������̯�Ӹ����հ���\n");

        message_vision(HIW "$N����̯�����ĸ��ǣ��ѻ���һ���Ե�����������վ��������\n" +NOR,me);
        me->delete_temp("on_bantan");
        me->delete("vendor_goods");
        return 1;
}

int do_stock(string arg)
{
        object obj,me,goods;
        int amount,value,i;
        mapping all_goods;
        string beishu,*args;
        
        me = this_player();
        if (!me->query("is_vendor")) return notify_fail("���ֲ������ˣ�Ϲ����ʲô����\n");
        if (!present("shangye zhizhao",me)) return notify_fail("�����ҵִ�ղ������ϣ������ߺ��������߲�����һ���µġ�\n");
        if (!me->query_temp("on_bantan")) return notify_fail("��������Ȱ�һ��̯λ(baitan)���ܷŻ��\n");
        if (!arg) return notify_fail("stock <����> n (����n������1��2��3��4��5����ʾ�û���ԭ��ֵ��n����ȱʡ�Ļ���ʾ���)\n");

        i = sizeof(args = explode(arg, " "));

        i--;
        if (!sscanf(args[i], "%d", amount)) 
                amount = 0;
        else arg = replace_string(arg," "+amount,"");

        if (!(goods = present(arg,me)) || !objectp(goods)) return notify_fail("�����ϲ�û��������ﰡ��\n");
        if (goods->is_character()) return notify_fail("�㲻�ܷ����˿ڣ�\n");
        if (goods->query("money_id")) return notify_fail("����ˣ�ǮҲ�������ۣ�\n");
        if (goods->is_item_make()) return notify_fail("��Ҳ̫���˰ɣ������Ķ����������˼ҵ�Ǯ��\n");
        if (sizeof(me->query("vendor_goods")) >= 10) return notify_fail("��һ��ֻ�ܰ���ʮ�ֻ�������������ֻ����ٰ������ֻ��\n");
        if (amount>5) return notify_fail("�������ԭ���屶���ۣ���Ҫ̫�ĺ�����\n");

        value = goods->query("base_value");
        if (!value) value = goods->query("value");
        if (amount)
        { 
                value = amount * value;
                beishu = (string)amount + "����";
        }
        else
        {
                value = value/2;
                beishu = "���";
        }
        if (!value) return notify_fail("���ֲ�ֵǮ���û���Ҳ����ϣ�̫û����ҵ��������\n");

        all_goods = me->query("vendor_goods");
        if (!all_goods) all_goods = ([ ]);
        all_goods[base_name(goods)] = value;
        me->set("vendor_goods",all_goods);
        message_vision(HIW "$N��"+ NOR + goods->name(1) + HIW +"����" + HIY + beishu + HIW"����̯�ӿ�ʼ���ۡ�\n"NOR,me);
        return 1;
}

int do_unstock(string arg)
{
        object obj,me,goods;
        int i,amount,value,have_it = 0;
        mapping all_goods;
        string *goods_key,beishu;
        
        me = this_player();
        if (!me->query("is_vendor")) return notify_fail("���ֲ������ˣ�Ϲ����ʲô����\n");
        if (!present("shangye zhizhao",me)) return notify_fail("�����ҵִ�ղ������ϣ������ߺ��������߲�����һ���µġ�\n");
        if (!me->query_temp("on_bantan")) return notify_fail("����̯�Ӷ�û�аᣬ����������\n");
        if (!arg) return notify_fail("unstock <����>\n");

        if (!(goods = present(arg,me))) return notify_fail("�����ڲ�û��������\n");
        all_goods = me->query("vendor_goods");
        if (!all_goods) return notify_fail("�����ڻ�û�а����κλ��\n");

        goods_key = keys(all_goods);
        for (i = 0;i < sizeof(goods_key);i++)
        {
                if (base_name(goods) == goods_key[i]) have_it = 1;
        }

        if (have_it) 
        {
                map_delete(all_goods,base_name(goods));
                message_vision(HIW "$N��" + NOR + goods->name(1) + HIW + "��̯�����������ˡ�\n",me);
        } else return notify_fail("��û�а������������̯�ӳ��۰���\n");

        me->set("vendor_goods",all_goods);
        return 1;
}

int do_checksellerrating()
{
	object me;

	me = this_player();
	tell_object(me, "��Ŀǰ�����������ǣ�"+me->query("n_Seller_Rating")+"�㡣\n");
	return 1;
}

int query_autoload()
{
	return 1;
}