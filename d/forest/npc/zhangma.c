// Code of ShenZhou
// Jay 7/12/96
//changed by wzfeng 99 12

inherit NPC;

void create()
{
        set_name("����", ({ "zhang ma", "ma", "zhang" }) );
        set("gender", "Ů��" );
	set("title", "Ӷ��");
        set("age", 48);
        set("long", 
	     "������ŮӶ��\n");
        set("str", 20);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);

        set("combat_exp", 500);

        set("attitude", "peaceful");
        set("inquiry", ([
            "����" : "������������ٵģ��Ҳ���������š�",
	    "here" : "�������������",
	    "name" : "�һ�û�ɼң������������˶಻����˼��",
	    "����" : "��������أ�",
	    "�����" : "�������Ǽ���ү��",
       ]) );

        setup();
        carry_object("/d/city/obj/cloth")->wear();
}
private void go_home()
{
	if( !living(this_object()) ) return;
        message_vision("$N��ɫ���ŵ��뿪�ˡ�\n", this_object());
        this_object()->move("/d/forest/gate");
	message_vision("$N�첽���˹�����\n", this_object());
}

void init()
{
        object ob;

        ::init();
        if( environment() != load_object("/d/forest/gate") ) {
		remove_call_out("go_home");
		call_out("go_home", 1);
		}
		else
			if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
    if ( !me )
	return;
    command("bow " + me->query("id"));
    command("say ��λ" + RANK_D->query_respect(me)+"���������Ǽ���ү���ٵİɡ�");
}

int accept_object(object me, object obj)
{
	if ((string)obj->query("name")=="����") {
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), obj); 
	message("vision",me->name()+"������һ֧���Ρ�\n",environment(me),
                ({me}));
	command("ah");
	command("say �����Ҽ�С��Ľ��Σ�Ī����λ"+RANK_D->query_respect(me)+"����������С�����ߵ��������ˣ�");
	command("look "+me->query("id"));
	command("say ������������ϯ��");
	message_vision("��������$N����������\n", me);
	me->move("/d/forest/yanting");
	message("vision", me->name()+"���������߽�����\n",environment(me),
		({me}));
	write("��һ��������ʢ�ľƲ˾ͳ���������\n");
	me->set("food",me->query("str")*10 + 120);
	me->set("water",me->query("str")*10 + 120);
	}
	else command("say ���������˼��");
        return 1;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
} 

