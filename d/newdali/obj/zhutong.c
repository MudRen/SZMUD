// Code of ShenZhou
// zhutong.c

inherit ITEM;
inherit F_LIQUID;

int do_empty(string);

void create()
{
	set_name("��Ͳ", ({ "zhu tong", "tong" }) );
	set_weight(500);
	set_max_encumbrance(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", "����һ֧��Ͳ������һ��������ɵģ���������װˮ��ʳ�\n");
		set("value", 10);
		set("material", "bamboo");
		set("max_liquid", 10);
        set("liquid", ([
			"type": "water",
			"name": "��ˮ",
			"remaining": 0,
			"drunk_supply": 0,
			]));
	}
	setup();
}

void init()
{
	::init();

	add_action("do_empty","dao");
}

int is_container() { return 1; }

int reject(object ob) 
{
	if (this_object()->query("liquid/remaining")) {
		notify_fail("��Ͳ��������ˮ����������Ŷ�����\n");
		return 1;
	}
   	if (!ob) return 1;  // what does it mean by ob==null?

	/*
	 * it is supposed to hold food and water only, so we check if the 
	 * object has food_remaining.
	 *
	 * -Chu
	 */
	if (ob->query("food_remaining")<1) {
 	    notify_fail("��Ͳ����ʪ�����壬��������²����ʰɡ�\n");
	    return 1;
        }

	if (sizeof(all_inventory(this_object()))<5) return 0;
	notify_fail("��֧��Ͳ�Ѿ�װ���ˣ���Ҳ�Ų����κζ����ˡ�\n");
	return 1;
}

int do_empty(string arg)
{
	object ob, me=this_player();

	if (!arg || (arg!="tong" && arg!="zhu tong")) return 0;

	if (query("liquid/remaining")) {
		message_vision("$N����Ͳ��װ��"+query("liquid/name")+"������\n",me);
		set("liquid/remaining", 0);
	}
	else tell_object(me,"��֧��Ͳ�ﲢû��װ��Ҫ�����Ķ�����\n");
	return 1;
}

int do_fill(string arg)
{
	if (!this_object()->id(arg)) return 0;
	if (this_player()->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	if (!environment(this_player())->query("resource/water"))
		return notify_fail("����û�еط�����װˮ��\n");

	if (sizeof(all_inventory(this_object()))>0)
		return notify_fail("�㻹���Ȱ���Ͳ����Ķ���ȡ������װˮ�ɡ�\n");

	if (query("liquid/remaining"))
		message_vision("$N��" + name() + "��ʣ�µ�" + query("liquid/name") + "������\n", this_player());
	message_vision("$N��" + name() + "װ����ˮ��\n", this_player());

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	set("liquid/type", "water");
	set("liquid/name", "��ˮ");
	set("liquid/remaining", this_object()->query("max_liquid"));
	set("liquid/drink_func", 0);

	return 1;
}
