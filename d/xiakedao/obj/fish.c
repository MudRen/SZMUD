//Cracked by Roath
// fish.c

inherit ITEM;

int decayed;

void create()
{
	set_name("����", ({ "fish", "yu" }) );
	set("long", "����һ����������Ĵ���㡣\n");
	set("unit", "��" );
	set("speical", 0);
	decayed = 0;
	if( clonep(this_object()) ) call_out("decay", 120, 1);
}

int is_live() { return decayed == 0; }
int is_halfdead() { return decayed == 1;}
int is_dead() { return decayed >= 2; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
	decayed = phase;
	switch(phase) {
		case 1:
			message("vision", query("name") + "����뿪ˮ̫���ˣ���������ˡ�\n", environment() );
			set("long",	"��������Ϊ�뿪ˮ̫���ˣ�����ȥ��������ˡ�\n");
			call_out("decay", 60, phase + 1);
			break;
		case 2:
			message("vision", query("name") + "���ˣ���ʼɢ����һ�ɳ�����\n", environment() );
			set_name("����", ({ "si yu", "fish" }) );
			set("long", "һ�����˵��㣬�����˰ɡ�\n");
			break;
	}
}
