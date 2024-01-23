using System;

namespace Script.Dynamic
{
    [AttributeUsage(AttributeTargets.Property)]
    public class OnlyPlaceableAttribute : Attribute
    {
        private string Value { get; set; } = "true";
    }
}