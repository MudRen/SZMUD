// Code of ShenZhou
// dealer.c ����
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands
// Ryu added category division, and sorted with quantity on 3/14/97.
// added cashflow control, snowbird
// fixed the minor bug, sdong, 4/8/2000

#include <dbase.h>

string is_vendor_good(string arg)
{
	string *goods;
	object ob;
	int i;

	if (arrayp(goods = query("vendor_goods"))) 
		for (i = 0; i < sizeof(goods); i++) 
			if (goods[i]->id(arg))
				return goods[i];
	return "";
}

int do_value(string arg)
{
	object ob;
	int value;

	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô�ļۣ�\n");
	
	if (ob->query("money_id"))
		return notify_fail("��û�ù�Ǯ����\n");

	value = ob->query("value");
	if (value < 1)
		write(ob->query("name") + "һ�Ĳ�ֵ��\n");
	else 
		write(ob->query("name") + "ֵ" + 
		MONEY_D->price_str(value * 70 / 100) + "��\n");
	return 1;
}

int do_sell(string arg)
{
	object ob, *inv;
	int value, i;
	inv = all_inventory(this_object());	
	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô��\n");

	if (ob->query("money_id"))
		return notify_fail("��������Ǯ������\n");

	if (ob->query("no_drop"))
		return notify_fail("����������������\n");

        if (ob->query("yaocai"))
                return notify_fail("��������ҩ�ģ����ܴ�ط��˰ɣ�\n"); 

	if (is_vendor_good(arg) != "") 
		return notify_fail("������ò��ã�\n");

	if (ob->query("food_supply"))
		return notify_fail("ʣ��ʣ���������Լ��ðɡ�\n");
	
        if (ob->query("shaolin"))
                return notify_fail("С��ֻ��һ���Դ����ɲ��������������\n");

	if (ob->query("no_sell"))
		return notify_fail("�ⶫ��С�����ˣ�ֻ��������ȥ��\n");

        if (ob->query("name") == "ѩ����")
               return notify_fail("����ʲô���ն���С�Ŀɲ����ա�\n"); 
	if (ob->query("skill_type") == "throwing")
		return notify_fail("�Բ��𣬱���һ���չ�������\n");

	value = ob->query("value");
	if (value < 30)
		write(ob->query("name") + "һ�Ĳ�ֵ��\n");
	else if (value > 1000000 )
		return notify_fail("����������С�Ŀ�����\n");
	else
	{
	// Adding the new cash flow control here
		if (MONEY_D->player_dealer_pay(this_player(), this_object(), value * 70 / 100) )
{		
			message_vision("$N������һ" + ob->query("unit") + 
				ob->query("name") + "��$n��\n", this_player(), this_object());
			for (i = 0; i < sizeof(inv); i++)
			if (inv[i]->query("name") == ob->query("name")){
			inv[i]->add("quantity", 1);
			destruct(ob);
			return 1;
			}
			ob->move(this_object());
			ob->set("quantity", 1);
			if (ob->query_amount())
			destruct(ob);
		}
		else
			return notify_fail("�Բ���С�����������ⶫ����\n");
	}

	return 1;
}

int do_list(string arg)
{
	string *goods;
	object *inv;
	int i;

	inv = all_inventory(this_object());

	if( arg=="" ) return 0;

	if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
		return notify_fail("Ŀǰû�п�����Ķ�����\n");
	
	if(! arg){
	if (arrayp(goods = query("vendor_goods"))){
                for (i = 0; i < sizeof(goods); i++)
                        printf("%30-s��%s\n", goods[i]->short(),
                        MONEY_D->price_str(goods[i]->query("value")));
        return 1;
	}
	else
	printf("���뿴��һ�񣿣�armor��weapon��drug��book or misc��\n");	
	return 1;
	}
	
	if( arg=="weapon" ) {
	printf("�������%s��������������\n", query("name"));
	for (i = 0; i < sizeof(inv); i++) 
		if (!inv[i]->query("equipped") && inv[i]->query("weapon_prop/damage")
		&&!inv[i]->query("money_id"))
		printf("%30-s��%s����ʣ%s%s��\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * 6 / 5),
		chinese_number(inv[i]->query("quantity")),
		inv[i]->query("unit"));
	return 1;
	}
	if( arg=="armor" ) {
        printf("�����з��δ������ۣ�\n", query("name"));
        for (i = 0; i < sizeof(inv); i++)
                if (!inv[i]->query("equipped") && inv[i]->query("armor_prop/armor") 
                &&!inv[i]->query("money_id"))
		printf("%30-s��%s����ʣ%s%s��\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * 6 / 5),
                chinese_number(inv[i]->query("quantity")),
		inv[i]->query("unit"));
        return 1;
        }
	if( arg=="book" ) {
        printf("�����������ۣ�\n", query("name"));
        for (i = 0; i < sizeof(inv); i++)
                if (!inv[i]->query("equipped") && inv[i]->query("material") == "paper"
                && !inv[i]->query("money_id"))
		printf("%30-s��%s����ʣ%s%s��\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * 6 / 5),
                chinese_number(inv[i]->query("quantity")),
		inv[i]->query("unit"));
        return 1;
        }
	if( arg=="drug" ) {
        printf("������ҩ����ۣ�\n", query("name"));
        for (i = 0; i < sizeof(inv); i++)
                if (!inv[i]->query("equipped") && inv[i]->query("medicine") 
                && !inv[i]->query("money_id"))
		printf("%30-s��%s����ʣ%s%s��\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * 6 / 5),
                chinese_number(inv[i]->query("quantity")),
		inv[i]->query("unit"));
        return 1;
        }
	if( arg=="misc" ) {
        printf("�������ӻ����ۣ�\n", query("name"));
        for (i = 0; i < sizeof(inv); i++)
                if (!inv[i]->query("equipped") && !inv[i]->query("armor_prop/armor")
		&& inv[i]->query("material") != "paper"
		&& inv[i]->query("medicine") < 1
		&& !inv[i]->query("weapon_prop/damage") && !inv[i]->query("money_id"))
		printf("%30-s��%s����ʣ%s%s��\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * 6 / 5),
                chinese_number(inv[i]->query("quantity")),
		inv[i]->query("unit"));
        return 1;
	}
}	

int do_buy(string arg)
{
	int i, amount, value, val_factor;
	string goods, ob_file, file;
	object ob, obj;
//	mapping fam;

//      if ( (fam = this_player()->query("family")) && fam["family_name"] == "ؤ��" ) 
//		return notify_fail("���Ǹ���л�����ʲ�ᶫ����\n");
	
	if( !arg ) return notify_fail("������ʲô��\n");

        if( sscanf(arg, "%d %s", amount, goods)!=2 )
	{
		amount = 1;
		goods = arg;
        }

	if( amount < 1 ) return notify_fail("��������٣�\n");
	if( amount > 10 ) return notify_fail("���ⲻ�������̡�\n");

	if( !(ob = present(goods, this_object())) )
		if( (ob_file = is_vendor_good(goods)) == "" )
			return notify_fail("������Ķ���������û�С�\n");
        if( ob && ob->query("money_id") )
                return notify_fail("������Ǯ������\n");

	if( !ob )
	{
		ob = new(ob_file);
		if( ob->query("base_unit") )
			ob->set_amount(amount);
		else ob->set("quantity", amount);
		val_factor = 10;
	}
	else
	{
		if( ob->query("equipped") )
			return notify_fail("������Ķ����Ҳ�����\n");

		if( ob->query("base_unit") && ob->query_amount() < amount )
			return notify_fail("����Ҫ�Ķ������ⲻ������\n");
		else if( amount > 2 && ob->query("quantity") < amount )
			return notify_fail("����Ҫ�Ķ������ⲻ������\n");
		val_factor = 12;
	}

        if( query_temp("busy") )
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	if( ob->query("value") * amount * val_factor / 10 > 1000000 )
		return notify_fail("ࡣ���С�����⣬������������������ţ�\n");

	switch( MONEY_D->player_pay(this_player(), ob->query("value") * amount * val_factor / 10) )
	{
	case 0:
		return notify_fail("��⵰��һ�ߴ���ȥ��\n");
	case 2:
		return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	default:
		set_temp("busy", 1);
		message_vision("$N��$n����������"+ chinese_number(amount) +
		( ob->query("base_unit") ? ob->query("base_unit") : ob->query("unit") ) + 
		ob->query("name") + "��\n", this_player(), this_object());

		if( ob->query("base_unit") )
		{
			if( ob->query_amount() > amount )
			{
				file = base_name(ob) + ".c";
				obj = new(file);
				obj->move(this_player());
				obj->set_amount(amount);
				ob->add_amount(-amount);
			}
			else ob->move(this_player());
		}
		else for( i=0; i < amount; i++ )
		{
			ob->add("quantity", -1);
			if( ob->query("quantity") < 1 )
				ob->move(this_player());
			else
			{
				file = base_name(ob) + ".c";
				obj = new(file);
				obj->move(this_player());
			}
		}
	}
	remove_call_out("enough_rest");
        call_out("enough_rest", 1);

	return 1;
}

void enough_rest()
{
        delete_temp("busy");
}


