//������ wanzitian.c
//Code by Scatter
//V. 2.0

#include <ansi.h>
inherit NPC;
void create()
{
set_name("������",({"Wan Zitian", "wan", "zi", "tian", "zitian"}));
set("title",HIW"��Ʒ����"NOR);
set("age",40);
set("gender","����");
set("long", "������Ʒ���ܵ��ܹܣ���Ʒ���ܴ���Ĵ�С������������
�������˶��������ܹܡ� \n");
setup();
carry_object("/clone/armor/cloth")->wear();

}


void init()
{
        object obj, me=this_player();
        ::init();
        add_action("do_cun", "cun");
        add_action("do_qu", "qu");
                add_action("do_check", "checkspace");

                if(!this_player()->query("itembank/olduser"))
                {
                        if(this_player()->query("itembank/item") > 0)
                        {
                                if(!this_player()->query("wposition"))
                                {
                                        this_player()->set("itembank/olduser", 1);
                                }
                                else
                                {
                                        obj = new( me->query("wposition") );
                                        obj->move(me);
                                        me->add("itembank/item", -1);
           
                                        if( me->query("itembank/item") < 1 )
                                        {
                                                me->delete("itembank/item");
                                        }

                                        me->delete("wposition");
                                        message_vision("$n��һ" + obj->query("unit") +
                                        obj->query("name") + "����$N��\n", this_player(), this_object());
                                        write("��Ϊ�µĹ��ܹ�ϵ�������ȰѶ��������㣬����Դ��´�һ�Ρ�\n������������  ���ݴ�����ʦ -- ��ڤ��\n");
                                }
                        }
                }
}

int do_check(string arg)
{
        object me = this_player();
        int maxspace;

        maxspace = me->query("itembank/maxitem") - me->query("itembank/item") + 2;
        write("�㻹���Է���� " + maxspace + " ��������\n");
                write("��Ŀǰ��ŵ���Ʒ��������\n");
                write(me->query("weaponpos"));
        return 1;
}


int do_cun(string arg)
{
       object ob, *inv;
       object me;
       int value, i;
       int totalitem, maxitem;
           string idname, wposname, tempdummy;

       me = this_player();
           maxitem = me->query("itembank/maxitem") + 1;

           if( !arg || sscanf(arg, "%s %s", tempdummy, idname)!=2 ) 
           {
                   write("��ʽ���ԣ�cun <�����Ʒ������> <Ϊ��ſռ�ȡ����>\n��: cun jian item1\n");
                   return 1;
           }

       inv = all_inventory(this_object());
       if (!arg || !(ob = present(tempdummy, this_player())))
                   return notify_fail("��Ҫ�ķ�ʲô��\n");
       if (me->query("itembank/item") > maxitem)
                   return notify_fail("�Բ������Ѿ��Ź���Ķ����ˣ�\n����ռ䲻����Ŀǰ����������ʦ����ÿ����һ����λ����Ϊ�������ƽ�\n");
       if(!ob->query("wposition"))
           return notify_fail("�����������Ǳ�׼��Ʒ�����ǲ����գ�\n");
       if (ob->query("food_supply"))
           return notify_fail("ʣ��ʣ�����ǲ��յġ�\n");
           

           wposname = "weaponpos/" + idname;
           // THIS IS A NEW WAY TO SAVE STANDAR ITEMS
                           if(!me->query(wposname))
                           {    
                                   me->set(wposname, ob->query("wposition"));
                                   me->add("itembank/item", 1);
                           }
                           else
                           {
                                   write("���Ѿ���λ��������������ˣ���ȡ������ְɡ�\n");
                                   return 1;                                       
                           }



                value = ob->query("value");
                message_vision("$N��һ" + ob->query("unit") +
        ob->query("name") + "����$n��\n", this_player(), this_object());
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
        return 1;
}


int do_qu(string arg)
{
    object me, obj;
        string tempdummy, idname;
        string weaponpos;
    me = this_player();

        if( !arg ) 
           {
                   write("��ʽ���ԣ�qu <��ſռ�ȡ����>\n��: qu item1\n");
                   return 1;
           }



    if (!me->query("itembank/item"))
    {
    write("��û�ж�����������ѽ!\n");
    return 1;
    }


        weaponpos = "weaponpos/" + arg;
        if(!me->query(weaponpos))
        {
                write("�Բ���û���ҵ���Ҫ�Ķ�������ȷ������û��\n");
                return 1;
        }

    obj = new( me->query(weaponpos) );

       obj->move(me);
       me->add("itembank/item", -1);
           
           if( me->query("itembank/item") < 1 )
           {
                   me->delete("itembank/item");
           }

           me->delete(weaponpos);
           message_vision("$n��һ" + obj->query("unit") +
       obj->query("name") + "����$N��\n", this_player(), this_object());

       return 1;
}

