 int main(object me, string arg)
{
        if(!me->query("shenzhou/pts"))
        {
                tell_object(me, "你目前没有对神州有任何贡献！\n");
        }

        else
        {
                tell_object(me, "你目前对神州的贡献度为 " + me->query("shenzhou/pts") + " 点！\n");
        }
        return 1;
}
