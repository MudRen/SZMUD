//Cracked by Roath
inherit ITEM;

void create()
{
        set_name( "������", ({ "shangshan ling", "ling", "iron" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ƣ��Ƶ�һ����һ��Ц������һ��ʲ��Ҳû��\n");
                set("value", 0);
                set("material", "iron");
        }
        setup();
}

string query_autoload()
{
        if( query("owner") == this_player()->query("id") )
                return query("name");
}
void autoload(string arg)
{       object it = this_object();
        object me = this_player(); 
        string desc;
                desc = "����һ�����ƣ��Ƶ�һ����һ��Ц������һ����š�" + me->query("name") + "��\n";
                it->set("long", desc);
                it->set("owner", me->query("id"));
                it->set("setted", 1);
}
        
        
