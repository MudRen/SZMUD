inherit F_CLEAN_UP;
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("����ǹ", ({ "gun" }) );
        set("long", "������\n");
        set_weight(100);
        set_max_encumbrance(100000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "steel");
                set("value", "100");
                }
        set("no_get", 1);
        set("no_steal", 1);
        enable_commands();

        setup();
}
void init()
{
        add_action("do_destroy","shoot");
}
        


int do_destroy(string arg)
{
                 object obj,me;
                 me=this_player();

                 if(me->query("id")!="rama")
                  return notify_fail("ʲô��\n");

                 if (!arg) return notify_fail("ָ���ʽ��destroy object.\n");

                 if(!objectp(obj = present(arg, environment(this_player()))))
                                         return notify_fail("����û������ˡ�\n");                
                                         if (!obj) obj = present(arg, me);               
                                         if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) );             
                                         if (!obj) return notify_fail("û���������....��\n");                   
                                         message_vision(CYN"$N�ͳ�һ�Ѽ���ǹ����׼$n�صĿ���һǹ����$p���һƬ������ʧ�ˣ���\n"NOR,me,obj);
                                         seteuid(ROOT_UID);              
                                         destruct(obj);                  
                                         if(obj){ write("���޷����������ݻ١�\n"); 
                                         return;}                   
                                         return 1; } 


