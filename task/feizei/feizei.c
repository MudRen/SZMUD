// feizei.c

#include <ansi.h>
inherit NPC;

void create()
{
    set("title",HIY"����ݵ�"NOR);
    set_name("����",({ "fei zei","fei","zei" }) );
    set("gender", "����" );
    set("age", 33);
    set("long", 
        "�����޶����ķ�����������һ��СС�������������ǲ�͵��ʲô�������֡�\n");

    set("int", 30);
    set("str", 35);
    set("con", 25);
    set("attitude", "heroism"); 
    set("dex", 40);
    set("shen_type", -1);
    set("qi", 15000);
    set("max_qi", 15000);
    set("jing", 15000);
    set("max_jing", 15000);
    set("neili", 18000);
    set("max_neili", 18000);
    set("jiali", 20);
    set("combat_exp", 15500000);
    set("score", 15000);

    set_skill("unarmed",600);
    set_skill("force", 600);
    set_skill("dodge", 600);
    set_skill("parry", 600);
    set_skill("sword", 600);
    set_skill("staff", 600);
    set_skill("hunyuan-zhang", 600);
    set_skill("huashan-shenfa",600);
    set_skill("huashan-shenfa",600);
    set_skill("huashan-shenfa",600);
    set_skill("huashan-jianfa", 600);
    set_skill("zixia-gong", 600);

    map_skill("force", "zixia-gong");
    map_skill("unarmed", "hunyuan-zhang");
    map_skill("dodge", "huashan-shenfa");
    map_skill("parry", "huashan-jianfa");
    map_skill("sword", "huashan-jianfa");
        
    set( "chat_chance", 1 );
    set("chat_msg", ({
            (: random_move :),
    }) );

    setup();
    carry_object( __DIR__ "changjian")->wield();
//        add_money("gold",1);

}

void init()
{
    add_action("do_follow","follow");
    add_action("do_follow","gen");  
}
        
void setupSkills( object obj )
{
    int exp = obj->query( "combat_exp" );
    int skill = obj->query_skill( "force" );
    if ( exp < 500000 )
        exp = 500000;
    exp = exp*5/4;
    
    if ( skill < 90 )
        skill = 90;
    skill = skill*6/5;
    set( "max_qi", obj->query( "max_qi" ) );
    set( "eff_qi", obj->query( "max_qi" ) );
    set( "qi", obj->query( "max_qi" ) );
    set( "max_neili", obj->query( "max_neili" ) );
    set( "neili", obj->query( "max_neili" ) );
    set( "max_jingli", obj->query( "max_jingli" ) );
    set( "eff_jingli", obj->query( "max_jingli" ) );
    set( "jingli", obj->query( "max_jingli" ) );
    set( "combat_exp", exp );
    set_skill("unarmed",skill);
    set_skill("force", skill);
    set_skill("dodge", skill);
    set_skill("parry", skill);
    set_skill("sword", skill);
    set_skill("staff", skill);
    set_skill("literate", skill);
    set_skill("hunyuan-zhang", skill);
    set_skill("huashan-shenfa",skill);
    set_skill("huashan-shenfa",skill);
    set_skill("huashan-jianfa", skill);
    set_skill("zixia-gong", skill);

    map_skill("force", "zixia-gong");
    map_skill("unarmed", "hunyuan-zhang");
    map_skill("dodge", "huashan-shenfa");
    map_skill("dodge", "huashan-shenfa");
    map_skill("parry", "huashan-jianfa");
    map_skill("sword", "huashan-jianfa");  
    set( "firstkill", obj->query( "id" ) );
}

void die()
{
    object player, corpse, lingzhi;
    string firstkill;
    player = this_object()->query_temp("last_damage_from"); 
    if(objectp(corpse=CHAR_D->make_corpse(this_object()))) ;
    {
        corpse->move(environment(this_object())); 
        lingzhi = new ( __DIR__ "lingzhi" );
        if ( objectp( player ) )
        {
            firstkill = query( "firstkill" );
            if ( stringp( firstkill ) && firstkill == player->query( "id" ) )
            {
                lingzhi->set( "benificial", player->query( "id" ) );
            }
        }                    
        lingzhi->move( corpse );
    }    
    message_vision("�������ڵ��ϣ������˼��¾����ˡ�\n",this_object());
    destruct( this_object() );
}

int accept_kill(object obj) 
{
    if ( !query( "setuped" ) )
    {
        set( "setuped", 1 );
        setupSkills( obj );
        ::accept_kill( obj );
    }
    else
    {
        if ( obj->query( "combat_exp" ) > query( "combat_exp" ) )
        {
            tell_object(obj,"�����޺޵�˵�����������"+RANK_D->query_rude(obj)+"��Ȼ�Ұ������Ը��ң��Ҳ�û��ôɵ�أ���\n");
            write("����һ������Ҳ�Ƶ�ȥ�ˣ�\n");
            // message, helper is too strong
            destruct( this_object() );
        }
    }
    return 1;
}

int do_follow()
{
    write("������ҹ���£����������Ը��٣�\n");
    return 1;
}
        

