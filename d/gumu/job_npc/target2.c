//Code of Shenzhou
//密探:target.c
//kissme,2002,2,14

inherit NPC;

string ask_mitan();

string *nm_yg =({
    "店小二","伙计","江湖豪客","趟子手","官兵",
      });

string *id_yg = ({
    "xiao er","huoji","jianghu haoke","tangzi shou","guan bing",
    });

  string *long_yg = ({
    "他长的尖嘴猴腮，一看就不是好人！\n",
    "他看上去像一个商人，可是给人的感觉总是怪怪的！\n",
    "他长的凶悍异常，脸上满是伤疤！\n",
    "他穿着趟子手的服饰，可是却没再走镖！\n",
    "他穿着官兵的服饰，一脸的横肉和伤疤！\n",
    });

void create()

{
    int i=random(sizeof(nm_yg));
    int rnd=random(100);

    set_name(nm_yg[i],({id_yg[i]}));
    set("long",long_yg[i]);
    set("shen_type",-1);
    set("shen",-100000);

    set("str",20);
    set("int",20);
    set("con",20);
    set("dex",20);

    set("no_refresh",1);

    set("inquiry",([
      "密探":(:ask_mitan:),
      ]));


    set("chat_chance",10);
    set("chat_msg",({
        (:random_move:),
      }));



    setup();
    carry_object("/clone/armor/beixin")->wear();
     remove_call_out("self_destruct");
    call_out("self_destruct",2500);
}

void init()
{
    object me,*inv;
    int i;

    me=this_object();
    inv=all_inventory(environment(me));


    for(i=0;i<sizeof(inv);i++){
     if(me->query("id")==inv[i]->query("id") || inv[i]->query("yang/ask")>1)
        me->kill_ob(inv[i]);
        }
    call_out("give_tishi",10);

}

string ask_mitan()
{
    object me,ob;

    me=this_player();
    ob=this_object();

     if(ob->query("yang/name")==me->query("id") && me->query("yang/job")){
        message_vision("只见$n脸色突然变了！\n",me,ob);
    me->add("yang/ask",1);
    if(me->query("yang/ask")>1){
      ob->kill_ob(me);
    me->kill_ob(ob);
    ob->set_leader(me);
      }
    return "你怎么知道？\n";
       }
      return "你说什么？\n";
}

void die()
{
    object ob,me,corpse;

    ob=this_object();
    me=query_temp("last_damage_from");

    message_vision("$N大喝一声，倒地而亡!\n",ob);

    if(objectp(corpse=CHAR_D->make_corpse(this_object())))
    corpse->move(environment(this_object()));

  if(ob->query("yang/name")==me->query("id") && me->query("yang/job"))
      me->add("yang/finish",1);
    me->delete("yang/ask");
    destruct(ob);
    return;
}

void self_destruct(){
    object me=this_object();
    message("vision",name(1)+"急急忙忙的离开了。\n",environment(me),me);
    destruct(me);
}


void give_tishi(){
    object me=this_player();
    object ob=this_object();

    tell_object(me,ob->query("name")+"看上去神色很紧张!\n",me,ob);
}
