// Code of ShenZhou
// /d/xueshan/npc/fsgelun.c
// Summer 9/26/1996.

inherit NPC;

#define BUSY_TIME 360
int do_fashi();
void create()
{
	set_name("���ײ�", ({ "ge lunbu", "ge", "lunbu" }));
	set_weight(3000000);
	set("long", 
"�������ڵĽ���ɮ�����ð�������������ŷ��������Ż��ۣ�ͷ����ñ��\n"
"������ɱ֮����\n");
	set("gender", "����");
	set("age", 20);
	set("attitude", "heroism");
	set("class","lama");
	set("shen_type", -1);
	set("str", 50);
	
	set("max_qi", 500);
	set("max_jing", 450);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 40);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 50);
	set_skill("dodge", 55);
	set_skill("parry", 60);
	set_skill("staff", 60);
	set_skill("cuff", 60);
	set_skill("hammer", 60);

        map_skill("parry", "jingang-chu");
        map_skill("staff", "jingang-chu");

        set("inquiry", ([
                "׼������" : (: do_fashi :),
		"preparation" : (: do_fashi :),
        ]) );

        setup();
	switch( random(3) )
        {
                case 0:
       			 carry_object("/clone/weapon/falun")->wield();
                         break;
		case 1:
			 carry_object("/d/qilian/obj/fachu")->wield();
			 break;
		case 2:
		 	 carry_object("/d/qilian/obj/faling")->wield();
	}
        carry_object(__DIR__"obj/lamajiasha")->wear();
}


int do_fashi()
{
	int i;
	object ob, me, mengzhu, room, *obj, room1, gang;
	ob=(present("fa tan", (environment(this_object()))));
	me=this_player();
	
	
	if (! present("fa tan", (environment(this_object())))){
	command("say ����æ���أ���ȥ��ֵ�յĸ��ײ��ɡ�");
	return 1;
	}

	if (me->query("class") != "lama"){
	command("say �����������Ǵ�������㳬���ˣ��ǰɣ�");
        return 1;
        }

	if ( me->query("family/family_name") != "ѩɽ��"
	&& me->query("family/family_name") != "Ѫ����"){
	command("say �����������Ǵ�������㳬���ˣ��ǰɣ�");
	return 1;
	}

	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");
        seteuid(getuid(me));
        if( !objectp(mengzhu = present("mengzhu", room)) )
        mengzhu = new("/clone/npc/meng-zhu");
        if (userp(me) && me->query("id") == mengzhu->query("winner") ){
	command("say ������Ϊ�����������ⷨ�����Ͼͱ��������");
	return 1;
	}

	if (me->query_skill("lamaism", 1) < 60){
	command("say �ܺã���ȥŪЩ�������õ��������ɡ�");
	return 1;
	}

    // add to involve the butter stuff
	if(!( room1 = find_object("/d/xueshan/dumudian")) )
		room1 = load_object("/d/xueshan/dumudian");
	if ( !objectp(gang = present("tong gang", room1)) ) {
    	command("say �������õ����Ͳ����ˣ����˸Ͽ�ȥ��һ�°ɣ�");
		return 1;
	}

	if (gang->query_current_liquid() < 40) {
	    command("say �������õ����Ͳ������ˣ�������ŪЩ�������ɡ�");
		return 1;
	}
	
        if ( time() < me->query("mp_job_time") + BUSY_TIME )
	{	command("say �����������һ���ܺķѾ�Ԫ�Ļ���˻�����ȥЪϢһ�°ɡ�");
		return 1;
	}
             // add by Yujie
	
	if (ob->query("burning")){
	obj = all_inventory(environment());
        for(i=0; i<sizeof(obj); i++){
        if( obj[i]->query("name") == ob->query("pending") )
        {
	command("say " +ob->query("pending") + "�������������£���λ" 
	+ RANK_D->query_respect(me) + "��һ���Ժ�\n");
	return 1;
	}
	}
	command("say " +ob->query("pending") + "���˷�������һ���᲻֪������ȥ�ˣ��治�󻰣�"
	+me->query("name") + "������" + ob->query("pending") + "���˰����µķ�������ɡ�\n");
	ob->set("pending", me->query("name"));
	return 1;
	}
/*
	if (me->query("name") == ob->query("last_burner")){
	command("say  ���˲��Ǹ����귨�����㻹����Ъһ����ɡ�");
	return 1;
	} 
*/
	if (ob->query("pending")){
        command("say " + ob->query("pending") + "���˸����귨�£���̳��δϨ�����ҵ���������"
	 + RANK_D->query_respect(me) + "���������°ɡ�\n");
	return 1;
	}
	
	else{
	command("say " + me->query("name") + RANK_D->query_respect(me) +
	"��Ҫ����λʩ��������ѽ��\n");
	me->set_temp("marks/��", 1);	
	return 1;
	}
}
int accept_object(object me, object ob)
{
	if (ob->query("beheaded")){
	command("say ����û��ͷ��");
	return 0;
	}

	if (ob->query("id") == "corpse" && present("fa tan", (environment(this_object())))
	&& me->query_temp("marks/��") == 1) {
	write("���ײ�����ææ�Ը���������̳����񣬵����͡�\n");
	me->delete_temp("marks/��");
	if (ob->query("combat_exp") > me->query("combat_exp")
	&& ob->query("my_killer") == me->query("id")){
	me->set_temp("award_pending", ob->query("combat_exp"));
	me->set_temp("award_pot", ob->query("combat_exp"));
	if (ob->query("was_userp"))
	me->set_temp("award_doubling", 1);
	}
	if(ob->query("combat_exp") > 1000000
	&& ob->query("my_killer") == me->query("id")) {
	me->set_temp("award_pot", ob->query("combat_exp"));
	}
	remove_call_out("preparing");
        call_out("preparing",5, me);
        return 1;
	}

	if (ob->name()=="���͹�"
        && me->query("class") == "lama"){
        if (me->query_skill("lamaism", 1) < 30){
	me->set("lama_butter",me->query("mud_age"));
        command ("bow");
        command ("say ��������ʩ����");
//        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        return 1;
        }
        if (me->query_skill("lamaism", 1) >= 30
        && me->query_skill("lamaism", 1) < 60){
        me->set("lama_butter",me->query("mud_age") + 7600);
        command ("bow");
        command ("say ��������ʩ����");
        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        return 1;
        }
   }
//	else if (ob->name()!="����" && ob->query("id") != "corpse") {
	else {
        write("���ײ�����¶���Ի�ı��顣\n");
        command ("shake");
//	remove_call_out("destroy_it");  // if player #10 give him some stuff,
					// 1 got dest but others 9 still on him   
        call_out("destroy_it", 1, ob);
        return 1;
        }
	return 1;
}	
void destroy_it (object ob)
{
        destruct(ob);
        return;

}
void preparing(object me)
{
	object ob, obj, room, tonggang, guan;
	ob=(present("fa tan", (environment(this_object()))));
	obj=(present("corpse", this_object()));
	ob->set("pending", me->query("name"));
        me->set("mp_job_time",time() );
	ob->set("in_use", 1);

	write("��һ�����һ��׼��ͣ����\n");
	command("say " + me->query("name") + "������Ϊ���鳬�Ȱɣ�\n");
/*	command("chat " + me->query("title") + me->query("name") +
                "���ˣ��ڽ���" + NATURE_D->game_time() + "����" 
		+ obj->query("victim_name") + "��\n");
*/
	command("put corpse in fa tan");
	obj->set_weight(ob->query_weight()*10);
	return;
}
