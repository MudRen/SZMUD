// Code of ShenZhou
// incense.c ���
// By Marz 11/11/96
// Ryu 12/5/96
inherit ITEM;

void init();
//void wear(int);

int worn;

void create()
{
	set_name("��",({"incense"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ֦����������㣬��������֦��������\n");
		set("unit", "֦");
		set("value", 10000);
    	}
	
	setup();
}

void init()
{
	worn = 0;
	call_out("wear", 120, 1); 
	add_action("do_light", "light");
}
int do_light(string arg)
{
        object  ob, me = this_player();
	if( !arg || arg=="" ) return 0;

    if (!present("fire", me) || !present("incense", me))  return 0;
    
               message("vision",this_player()->name() + "�ͳ����۰����ȼ��\n",
                        environment(me), ({me}) );
               write("���ͳ����۰����ȼ��\n");
		ob = new("/d/xingxiu/obj/incense2");
		ob->move(me);
		destruct(this_object());
        return 1;
}

/*
void wear(int phase)
{
	worn = phase;
	switch(phase) {
	case 1:
		set("long", "����һ֦�㣬���Ѿ���ʼʧȥ��ζ�ˡ�\n");
		call_out("wear", 120, phase+1); 
		break;
	case 2:
		set("long", "����һ֦���˺ܾõ��㣬������ȫʧȥ�����ˡ�\n");
		call_out("wear", 120, phase+1); 
		break;
	case 3:
		destruct(this_object());
		break;
	}	
}
*/
// End of File 
