// Ϊspark��д����ͯ������  :)  babi-wawa.c
// by naihe  02-05-31  for spark.


#include <ansi.h>
inherit ITEM;

string head_now,head,shipin,shipin_wear,color_shipin,color,dress,
color="����ͨͨ��",
dress="С����ȹ",
head_now="����",
shipin="none";

void now();

void create()
{
	set_name(HIM"�ű�����"NOR, ({"babi", "baby","babi wawa"}));
	set("long","����һ��Ư���İű����ޣ�����Ը������·�����ͷ�������ߴ���Ʒ�� :)\n");
	set_weight(100);
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
	add_action("do_huan","huan");
	add_action("do_shu","shu");
	add_action("do_dai","dai");
}

int do_shu(string arg)
{
	object me=this_player();

	if(!arg) return notify_fail("��Ҫ������ʲô��\n");
	if(arg!="tou" && arg!="head" && arg!="toufa" && arg!="hair") return notify_fail("��Ҫ������ʲô��\n");

	if(head!="good")
	{
		message_vision(CYN"$N���������"HIM"�ű�����"NOR+CYN"��ϸ�ĵذ�����ͷ�������������ġ�\n"NOR,me);
		head="good";
		head_now="��������";
	}

	else
	{
		message_vision(CYN"$N����"HIM"�ű�����"NOR+CYN"��������ͷ���ᰡ���ȴԽ��Խ���ˡ�\n"NOR,me);
		head="bad";
		head_now="����";
	}

	now();
	return 1;
}

int do_dai(string arg)
{
	if(!arg) return notify_fail("��Ҫ������ʲô��\n");

	if(arg!="ring" && arg!="earring" && arg!="necklace" && arg!="none") return notify_fail("���Ը������ϣ���ָ��ring����������necklace���������earring������ȡ�£�none����\n");

	switch(random(5))
	{
		case 0:color_shipin=""HIY"";
		break;
		case 1:color_shipin=""HIG"";
		break;
		case 2:color_shipin=""HIW"";
		break;
		case 3:color_shipin=""HIM"";
		break;
		case 4:color_shipin=""HIC"";
		break;
	}

	if(arg=="ring")
	{
		if(shipin!="none") message_vision(CYN"$N��"HIM"�ű�����"NOR+CYN""+shipin_wear+"�ŵ�С��ָȡ��������\n"NOR,this_player());
		shipin_wear="��";
		shipin="һ��"+color_shipin+"С��ָ"NOR"";
	}

	if(arg=="earring")
	{
		if(shipin!="none") message_vision(CYN"$N��"HIM"�ű�����"NOR+CYN""+shipin_wear+"�ŵ�С����ȡ��������\n"NOR,this_player());
		shipin_wear="��";
		shipin="һ��"+color_shipin+"С����"NOR"";
	}

	if(arg=="necklace")
	{
		if(shipin!="none") message_vision(CYN"$N��"HIM"�ű�����"NOR+CYN""+shipin_wear+"�ŵ�С����ȡ��������\n"NOR,this_player());
		shipin_wear="��";
		shipin="һ��"+color_shipin+"С����"NOR"";
	}

	if(arg=="none")
	{
		message_vision(CYN"$N����ذ�"HIM"�ű�����"NOR+CYN""+shipin_wear+"�ŵ�"+shipin+""CYN"ȡ��������\n"NOR,this_player());
		shipin="none";
	}

	else message_vision(CYN"$N����ظ�"HIM"�ű�����"NOR+CYN""+shipin_wear+"����"+shipin+"��\n"NOR,this_player());

	now();
	return 1;
}

int do_huan(string arg)
{
	string tempa,tempb;

        if (!arg || sscanf(arg, "%s %s", tempa, tempb) != 2)
	        return notify_fail("ָ���ʽ�� huan <��ɫ> <��װ> .\n");

	if(tempa!="HIR" && tempa!="HIG" && tempa!="HIY" && tempa!="HIB" && tempa!="HIM" && tempa!="HIC" && tempa!="HIW" && tempa!="RED" && tempa!="GRN" && tempa!="YEL" && tempa!="BLU" && tempa!="MAG" && tempa!="CYN" && tempa!="WHT") return notify_fail("��Ҫ������ʲô��ɫ�ķ�װ�󣿣�help color��\n");

	if(tempb!="xiaoqun" && tempb!="hunsha" && tempb!="changqun")
		return notify_fail("��Ҫ������ʲô��װ�󣿣�xiaoqun--С����ȹ hunsha--����� changqun--¶����ȹ�� \n");

	if(tempb=="xiaoqun") dress="С����ȹ";
	if(tempb=="hunsha") dress="��ɴ";
	if(tempb=="changqun") dress="¶����ȹ";

	if(tempa=="HIR") color=""HIR"��ɫ"NOR"";
	if(tempa=="HIG") color=""HIG"��ɫ"NOR"";
	if(tempa=="HIY") color=""HIY"��ɫ"NOR"";
	if(tempa=="HIB") color=""HIB"����ɫ"NOR"";
	if(tempa=="HIM") color=""HIM"�ۺ�ɫ"NOR"";
	if(tempa=="HIC") color=""HIC"����ɫ"NOR"";
	if(tempa=="HIW") color=""HIW"��ɫ"NOR"";

	if(tempa=="RED") color=""RED"����ɫ"NOR"";
	if(tempa=="GRN") color=""GRN"ǳ��ɫ"NOR"";
	if(tempa=="YEL") color=""YEL"����ɫ"NOR"";
	if(tempa=="BLU") color=""BLU"����ɫ"NOR"";
	if(tempa=="MAG") color=""MAG"ǳ��ɫ"NOR"";
	if(tempa=="CYN") color=""CYN"����ɫ"NOR"";
	if(tempa=="WHT") color=""WHT"ǳ��ɫ"NOR"";

	message_vision(CYN"$N����ظ�"HIM"�ű�����"NOR+CYN"������һ��"NOR""+color+""CYN""+dress+""CYN"��\n"NOR,this_player());
	now();
	return 1;
}

void now()
{
	if(shipin!="none")
	{
		this_object()->set("long","����һ������"+color+dress+"��"HIM"�ű�����"NOR"��ͷ��"+head_now+"�ģ���"+shipin_wear+"��"+shipin+"���ɰ����ˡ�\n����Ը������·�����ͷ�������ߴ���Ʒ�� :)\n");
	}

	else this_object()->set("long","����һ������"+color+dress+"��"HIM"�ű�����"NOR"��ͷ��"+head_now+"�ģ��ɰ����ˡ�\n����Ը������·�����ͷ�������ߴ���Ʒ�� :)\n");
}

