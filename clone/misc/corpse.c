// Code of ShenZhou
// corpse.c

inherit ITEM;
inherit F_FOOD;

int decayed;

void create()
{
	set_name("����ʬ��", ({ "corpse" }) );
	set("long", "����һ������ʬ�塣\n");
	set("unit", "��" );
	decayed = 0;
	if( clonep(this_object()) ) call_out("decay", 1, 0);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
	decayed = phase;
	switch(phase) {
		case 0:
		        set("food_remaining", 4);
        		set("food_supply", query_weight()/1000);
        		set("food_race","Ұ��");
			call_out("decay", 120, 1);
			break;
		case 1:
			message("vision", query("name") + "��ʼ�����ˣ�����һ�����ŵĶ����\n", environment() );
			delete("food_supply");
			switch(query("gender")) {
				case "����":
					set_name("���õ���ʬ", ({ "corpse", "ʬ��" }) );
				case "Ů��":
					set_name("���õ�Ůʬ", ({ "corpse", "ʬ��" }) );
				default:
					set_name("���õ�ʬ��", ({ "corpse", "ʬ��" }) );
			}
			set("long",	"���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n");
			call_out("decay", 60, phase + 1);
			break;
		case 2:
			message("vision", query("name") + "���紵Ǭ�ˣ����һ�ߺ��ǡ�\n", environment() );
			set_name("����", ({ "skeleton", "����" }) );
			set_weight(query_weight()/5);
			set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			message("vision", "һ��紵������" + query("name") + "���ɹǻҴ�ɢ�ˡ�\n", environment() );
			if( environment() ) {
				object *inv;
				int i;
				
				inv = all_inventory(this_object());
				for(i=0; i<sizeof(inv); i++) {
					if ( inv[i]->query("no_drop") ) continue;
					inv[i]->move(environment());
				}
			}
			destruct(this_object());
			break;
	}
}
